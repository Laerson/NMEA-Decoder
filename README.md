# NMEA-Decoder
Uma aplicação capaz de traduzir mensagens recebidas por um gps pra um formato legível.

## Especificação
Os sistemas que usam GPS no dia a dia, se comunicam com os satélites por meio de um padrão de comunicação mantido pela NMEA, chamado de NMEA 0183, esse padrão define uma série de protocolos para a comunicação de dispositivos eletrônicos marítimos como GPSs, Sonares, Bússolas, etc. 

Quando um dispositivo capaz de receber sinal dos satélites que fazem parte do GPS recebe um sinal, esse sinal é um código ASCII similar ao seguinte exemplo:

`$GPGGA,092750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76
$GPGSA,A,3,10,07,05,02,29,04,08,13,,,,,1.72,1.03,1.38*0A
$GPGSV,3,1,11,10,63,137,17,07,61,098,15,05,59,290,20,08,54,157,30*70
$GPGSV,3,2,11,02,39,223,19,13,28,070,17,26,23,252,,04,14,186,14*79
$GPGSV,3,3,11,29,09,301,24,16,09,020,,36,,,*76
$GPRMC,092750.000,A,5321.6802,N,00630.3372,W,0.02,31.66,280511,,,A*43
$GPGGA,092751.000,5321.6802,N,00630.3371,W,1,8,1.03,61.7,M,55.3,M,,*75
$GPGSA,A,3,10,07,05,02,29,04,08,13,,,,,1.72,1.03,1.38*0A
$GPGSV,3,1,11,10,63,137,17,07,61,098,15,05,59,290,20,08,54,157,30*70
$GPGSV,3,2,11,02,39,223,16,13,28,070,17,26,23,252,,04,14,186,15*77
$GPGSV,3,3,11,29,09,301,24,16,09,020,,36,,,*76
$GPRMC,092751.000,A,5321.6802,N,00630.3371,W,0.06,31.66,280511,,,A*45`

Esse código tem várias informações, como a latitude, longitude, altitude, quantos e quais satélites foram usados, diluição da precisão horizontal, dados de correção, velocidade, data e hora do envio do sinal, e um checksum pra detectação de erros na transmissão.

A aplicação vai ser capaz de:

1- Decodificar um sinal NMEA pra um formato legível
2- Codificar dados de localização pra o formato NMEA
3- Verificar se o sinal é válido, usando a checksum
