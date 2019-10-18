--checa se a sentenca começa com "$GPGGA"

-------------------------------------------------------------

--Separa a parte do checksum do resto da sentença
splitCheckSum :: String -> [String]
splitCheckSum [] = [""]
splitCheckSum (c:cs)
    | c == '*' = "" : rest
    | otherwise = (c : head rest) : tail rest
    where
        rest = splitCheckSum cs

--separa a string por virgulas
split :: String -> [String]
split [] = [""]
split (c:cs)
    | (c == ',' || c == '*') = "" : rest
    | otherwise = (c : head rest) : tail rest
    where
        rest = split cs
dataTypeParser :: String -> String
dataTypeParser sentence = head (split sentence)

timeParser :: String -> String
timeParser sentence = head(tail(split sentence))

latParser :: String -> String
latParser sentence = head (tail(tail(split sentence)))


poloParser :: String -> String
poloParser sentence = head (tail((tail(tail(split sentence)))))

longParser :: String -> String
longParser sentence = head (tail(tail((tail(tail(split sentence))))))

eastWestParser :: String -> String
eastWestParser sentence = head (tail(tail(tail((tail(tail(split sentence)))))))

gpsQualityParser :: String -> String 
gpsQualityParser sentence = head (tail(tail(tail(tail((tail(tail(split sentence))))))))

numberOfSatellitesParser :: String -> String
numberOfSatellitesParser sentence = head (tail(tail(tail(tail(tail((tail(tail(split sentence)))))))))

horizontalDillutionParser :: String -> String
horizontalDillutionParser sentence = head (tail(tail(tail(tail(tail(tail((tail(tail(split sentence))))))))))

altitudeParser :: String -> String
altitudeParser sentence = head (tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence)))))))))))

altitudeUnitParser :: String -> String
altitudeUnitParser sentence = head (tail(tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence))))))))))))

geoidalParser :: String -> String
geoidalParser sentence = head (tail(tail(tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence)))))))))))))

geoidalUnitParser :: String -> String
geoidalUnitParser sentence = head (tail(tail(tail(tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence))))))))))))))

ageParser :: String -> String
ageParser sentence = head (tail(tail(tail(tail(tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence)))))))))))))))

idParser :: String -> String
idParser sentence = head (tail(tail(tail(tail(tail(tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence))))))))))))))))

checksumParser :: String -> String
checksumParser sentence = head (tail(tail(tail(tail(tail(tail(tail(tail(tail(tail(tail(tail(tail((tail(tail(split sentence)))))))))))))))))

