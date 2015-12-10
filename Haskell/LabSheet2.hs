import Data.Char

inRange :: Int -> Int -> [Int] -> [Int]
inRange _ _ [] = [];
inRange a b (x:xs) 
    | x < a     = inRange a b xs
    | x > b     = inRange a b xs
    | otherwise = x : inRange a b xs

countPositives :: [Int] -> Int
countPositives [] = 0
countPositives (x:xs)
    | x >= 0    = 1 + countPositives xs
    | otherwise = countPositives xs

capitalised :: String -> String
capitalised [] = []
capitalised (x:xs) = toUpper x : lower xs
    where
        lower [] = []
        lower (x:xs) = toLower x : lower xs

title :: [String] -> [String]
title [] = []
title (x:xs) = capitalised x : nextWords xs
    where 
        nextWords [] = []
        nextWords (x:xs)
            | length x > 3 = capitalised x : nextWords xs
            | otherwise    = x : nextWords xs

isort :: (Ord a) => [a] -> [a]
isort [] = []
isort (x:xs) = insert x (isort xs)
    where
        insert x [] = [x]
        insert a list@(x:xs)
            | a < x     =  a : list
            | otherwise =  x : (insert a xs)

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] [] = []
merge x [] = x
merge [] y = y
merge unsplitX@(x:xs) unsplitY@(y:ys)
    | x < y= x : merge xs unsplitY
    | x > y  = y : merge unsplitX ys
    | otherwise = x : y : merge xs ys

msort :: (Ord a) => [a] -> [a]
msort xs 
    | (length xs) > 1 = merge (msort lower) (msort higher)
    | otherwise = xs
    where (lower, higher) = split(xs)

split :: (Ord a) => [a] -> ([a],[a])
split xs = (take n xs, drop n xs)
    where n = (length xs) `div` 2

-- CIPHER

rotor :: Int -> String -> String
rotor n xs
    | n <= 0 = error "n is too small"
    | (length xs) < n = error "n is too large"
    | otherwise = (drop n xs) ++ (take n xs)

makeKey :: Int -> [(Char, Char)]
makeKey n = zip ['A'..'Z'] (rotor n ['A'..'Z']) 

lookUp :: Char -> [(Char, Char)] -> Char
lookUp x [(a,b)] = b

encipher :: Int -> Char -> Char
encipher n a b = 