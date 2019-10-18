--import Data.Char
--import System.IO  


--main = do
--  putStrLn "NMEA Sentence decode"
--  putStrLn "Do you want to:"
--  putStrLn "1 - Decode a NMEA sentence"
--  putStrLn "2 - Create a NMEA sentence(Not implemented yet)"

--  option <- getLine



--checa se a sentenca começa com "$GPGGA"

-------------------------------------------------------------

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

--------------------------------------------------------------

timeDecode :: String -> String
timeDecode [] = ""
timeDecode (rawTime)
      |length(rawTime) == 2 = (rawTime) ++ "H"
      |length(rawTime) == 4 = timeDecode([head(rawTime)] ++ [head(tail(rawTime))]) ++ " : " ++ tail(tail(rawTime)) ++ "M"
      |length(rawTime) == 6 = timeDecode([head(rawTime)] ++ [head(tail(rawTime))] ++ [head(tail(tail(rawTime)))] ++ [head(tail(tail(tail(rawTime))))]) ++ " : " ++ tail(tail(tail(tail(rawTime)))) ++ "S"
      |length(rawTime) > 6 = timeDecode([head(rawTime)] ++ [head(tail(rawTime))] ++ [head(tail(tail(rawTime)))] ++ [head(tail(tail(tail(rawTime))))]) ++ " : " ++ [head(tail(tail(tail(tail(rawTime)))))] ++ [head(tail(tail(tail(tail(tail(rawTime))))))] ++ "," ++ tail(tail(tail(tail(tail(tail(rawTime)))))) ++ "S"
      |otherwise "invalid time format"
      