#include <string.h>
#include <stdio.h>
#include "decoder.h"


int main(void)
{
    printf("NMEA Sentence decoder\n\n");
    printf("Do you want to:\n");
    printf("\t1. Decode a NMEA sentence\n");
    printf("\t2. Create a NMEA sentence(Not implemented yet)\n");

    int option;

    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Type the NMEA sentence you want to decode: ");
        char sentence [90];
        scanf("%s", &sentence);
        decode(sentence);
        break;
    
    default:
        break;
    }
}

void decode(char sentence[])
{

    
    
    if (! gpVer(sentence))
    {
        printf("%s\n", "Invalid sentence");
    }

    else
    {
        
        char * data = dataType(sentence);

        if (!strcmp(data, "GGA,"))
        {
            gga(sentence + 7);
        }
        else
        {
            printf("%s\n", "Unknown Datatype");
        }
    }
}

int gpVer(char sentence[]) {
    if (sentence[0] != '$')
    {
        return 0;
    }
    else if (sentence[1] != 'G')
    {
        return 0;
    }
    else if (sentence[2] != 'P')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char * dataType(char sentence[]) {
    static char data[5];

    data[0] = sentence[3];
    data[1] = sentence[4];
    data[2] = sentence[5];
    data[3] = sentence[6];
    data[4] = '\0';

    return data;
}

void gga(char sentence[]) {
    char time [20] = "";
    char latitude[20] = "";
    char polo = '\0';
    char longitude [20] = "";
    char eastWest = '\0';
    char gpsQualityIndicator = '0'; // non null
    char numberOfSatellites [10] = "";
    char horizontalDilution [20] = "";
    char altitude [20] = "";
    char unitOfAltitude = 'M';
    char geoidalSeparation [20] = "";
    char unitOfGeoidalSeparation = 'M';
    char dgpsAge [20] = "";
    char dgpsID [20] = "";
    char checksum [4];


    

    int sentenceCounter = 0;
    int i = 0;

    //Time
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        time[i] = sentence[sentenceCounter];
        sentenceCounter ++;
        i++;

        
    }


//latitude
    sentenceCounter ++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        latitude[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
        
    }


    //polo
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        //Tem quer ser N ou S
        polo = sentence[sentenceCounter];
        sentenceCounter++;
    }
    
    //longitude
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        longitude[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //eastWest
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        eastWest = sentence[sentenceCounter];
        sentenceCounter++;
    }

    //gpsQuality
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        gpsQualityIndicator = sentence[sentenceCounter];
        sentenceCounter++;
    }

    //numberOfSatellites
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        numberOfSatellites[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //horizontal Dilution
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        horizontalDilution[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //Antenna Altitude
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        altitude[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //Units of altitude.
    //erro se não for M
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        unitOfAltitude = sentence[sentenceCounter];
        sentenceCounter++;
    }

    //Geoidal separation
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        geoidalSeparation[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //units of geoidal sep
    //erro se não for M
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        unitOfGeoidalSeparation = sentence[sentenceCounter];
        sentenceCounter++;
    }

    //dgpsAGE
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        dgpsAge[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //DGPSID
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != '*')
    {
        dgpsID[i] = sentence[sentenceCounter];
        sentenceCounter++;
        i++;
    }

    //checksum
    // tem que ser exatamente dois dígitos
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence))
    {
       checksum[i] = sentence[sentenceCounter];
       sentenceCounter++;
       i++;
    }

    //time of the signal
    printf("Time of the position report (UTC): ");
    for(i = 0; i < strlen(time); i++) {
        if (i == 2 || i == 4)
        {
            printf(": ");
        }
        
        printf("%c", time[i]);

        switch (i)
        {
        case 1:
            printf("h ");
            break;

        case 3:
            printf("m ");
            break;
        
        default:
            break;
        }

        if (strlen(time) >= 6 && i == strlen(time) - 1)
        {
           printf("s\n\n");
        }
        
    }

    //latitude
    int decimalPointIndex = -1;
    for(i = 0; i < strlen(latitude); i ++) {
        if(latitude[i] == '.') {
            decimalPointIndex = i;
        }
        //se o decimalpoint não for encontrado, é erro de entrada
    }

    char graus [4] = "0";
    char minutes [3] = "";

    for(i = decimalPointIndex - 1; i >= 0; i--) {
        if(i >= decimalPointIndex - 2) {
                switch (decimalPointIndex - i)
                {
                case 1:
                    minutes[1] = latitude[i];
                    break;

                case 2:
                    minutes[0] = latitude[i];
                
                default:
                    break;
                }            
        }

        else
        {
            switch (i)
            {
            case 0:
                graus[0] = latitude[i];
                break;

            case 1:
                graus[1] = latitude[i];
                break;

            case 2:
                graus[2] = latitude[i];
                break;
            
            default:
                break;
            }
        }        
    }

    printf("Latitude: %s\'%s%s %cº\n\n", graus, minutes, latitude + decimalPointIndex, polo);

    //longitude
    for(i = 0; i < strlen(longitude); i ++) {
        if(longitude[i] == '.') {
            decimalPointIndex = i;
        }
        //se o decimalpoint não for encontrado, é erro de entrada
    }

    char graus2 [4] = "0";
    char minutes2 [3] = "";

    for(i = decimalPointIndex - 1; i >= 0; i--) {
        if(i >= decimalPointIndex - 2) {
                switch (decimalPointIndex - i)
                {
                case 1:
                    minutes2[1] = longitude[i];
                    break;

                case 2:
                    minutes2[0] = longitude[i];
                
                default:
                    break;
                }            
        }

        else
        {
            switch (i)
            {
            case 0:
                graus2[0] = longitude[i];
                break;

            case 1:
                graus2[1] = longitude[i];
                break;

            case 2:
                graus2[2] = longitude[i];
                break;
            
            default:
                break;
            }
        }        
    }

    printf("Longitude: %s\'%s%s %cº\n\n", graus2, minutes2, longitude + decimalPointIndex, eastWest);

    printf("GPS Quality: ");
    switch (gpsQualityIndicator)
    {
    case 0:
        printf("fix not avaliable\n\n");
        break;

    case 1:
        printf("GPS fix\n\n");
        break;

    case 2:
        printf("DGPS fix\n\n");
        break;
    
    default:
        printf("\n\n");
        break;
    }

    printf("Number of satellites in use: %s\n\n", numberOfSatellites);

    printf("Horizontal dillution of precision: %s m\n\n", horizontalDilution);

    printf("Altitude: %s %c\n\n", altitude, unitOfAltitude);

    printf("Geoidal Separation: %s %c\n\n", geoidalSeparation, unitOfGeoidalSeparation);

    printf("Age of differential GPS data, time in seconds since last SC104 type 1 or 9 update: ");
    printf("%s s\n\n", dgpsAge);

    printf("Differential reference station ID: %s\n\n", dgpsID);

    printf("checksum of the sentence received: %s\n", checksum);
    printf("checksum expected: %x\n", checksumF(sentence + 1));
    printf("if the values above don't match, the data is invalid\n\n");



}

int checksumF(char sentence[]) {
    int sum = 0;
    int i;
    for(i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == '*') {
            break;
        }
        sum = sentence[i] ^ sum;
    }

    return sum;
}






