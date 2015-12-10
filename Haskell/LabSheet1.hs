import Data.Char

square :: Float -> Float
square length = 
    if length > 0
        then length * 4
        else -1
        
pyth :: Integer -> Integer -> Integer
pyth a b = a^2 + b^2


isTriple :: Integer -> Integer -> Integer -> Bool
isTriple a b c =
    if a^2 + b^2 == c^2
        then True
        else False
        
isTripleAny :: Integer -> Integer -> Integer -> Bool
isTripleAny a b c =
    if a^2 + b^2 == c^2
        then True
        else if b^2 + c^2 == a^2
            then True
            else if c^2 + a^2 == b^2
                then True
                else False
                
halfEvens :: [Int] -> [Int]
halfEvens xs = [ if x `mod` 2 == 0 then x `div` 2 else x | x <- xs]

inRange :: Int -> Int -> [Int] -> [Int]
inRange a b c = [x | x <- c, x >= a, x <= b]

countPositives :: [Int] -> Int
countPositives a = length (filter (>=0) a)

capitalised :: String -> String
capitalised (x:xs) = toUpper x : [toLower xs | xs <- xs]

title :: [String] -> [String]
-- title [] = "Empty!"
title (x:xs) = capitalised x : [if length xs > 3 then capitalised xs else [toLower xs | xs <- xs] | xs <- xs]