#include <string.h>
#include <stdio.h>
#include "decoder.h"


/*int main(void)
{

    decode("$GPGGA,1234,5");
    return 0;
}*/

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
    char time [10] = "";
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
    }

    //gpsQuality
    sentenceCounter++;
    i = 0;
    while (sentenceCounter < strlen(sentence) && sentence[sentenceCounter] != ',')
    {
        gpsQualityIndicator = sentence[sentenceCounter];
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
}






