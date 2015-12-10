import Data.Char
import Test.QuickCheck

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs)
    | f x = x : filter' f xs
    | otherwise = filter' f xs

length1 :: [a] -> Int
length1 xs = foldr (+) 0 (map (\x->1) xs)

length2 :: [a] -> Int
length2 [] = 0
length2 (x:xs) = 1 + length2 xs

capitalised :: String -> String
capitalised (x:xs) = toUpper x : lowerCase xs
    where lowerCase [] = []
          lowerCase (x:xs) = toLower x: lowerCase xs

name :: String -> String
name [] = []
name (x:xs) = toUpper x: name xs

toUpperCase x = [y|y<-x,elem y ['A'..'Z']]

alpha xs = map (\x->True) xs

orBools xs = [equalityOf c d | (c,d) <- xs]
    where equalityOf x y = x == y

returnFive _ = 5

checkHead :: (Eq a) => a -> [a] -> Bool
checkHead a (x:xs)
    | a == x = True
    | otherwise = False

max' :: (Ord a) => [a] -> a
max' xs = foldr max (head xs) xs

and' :: (Eq a) => a -> a -> Bool
and' a b
    | a == b = True
    | otherwise = False

id' :: a -> a
id' a = a

-- oneTwoThree :: [a] -> Int
-- oneTwoThree xs
--     | xs == "IEP" = 0
--     | xs == [] = 1
--     | xs = 2
--     | otherwise = 3

listFunctionF :: (c -> b) -> (c -> d) -> c -> (b, d)
listFunctionF f g x = (f x, g x)

listFunction :: [(a -> b)] -> a -> [b]
listFunction [] a = []
listFunction (f:fs) a = f a : listFunction fs a

double' :: [Int] -> [Int]
double' xs = [x * 2| x <- xs]

allFactors :: Int -> [Int]
allFactors x = [x `div` y | y <- [1..x], x `mod` y == 0]

removeLowerCase :: String -> String
removeLowerCase xs = [x | x <- xs, x `elem` ['A'..'Z']]

combinations :: [a] -> [b] -> [(a, b)]
combinations xs ys = [(x,y) | x<-xs, y<-ys]

map' :: (a -> b) -> [a] -> [b]
map' f xs = [f x | x <- xs]

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' f xs = [x | x <- xs, f x == True]

hoLength :: [a] -> Int
hoLength = foldr (+) 0 . map (\x -> 1) 

hoDouble :: [Int] -> [Int]
hoDouble = map (*2)

hoFactors :: Int -> [Int]
hoFactors n  = filter (\x -> n `mod` x == 0) [1..n]

hoRemoveLower :: String -> String
hoRemoveLower = filter (\x -> x `elem` ['A'..'Z'])

hoOppositeBool :: [Bool] -> [Bool]
hoOppositeBool = map (\x -> if x == True then False else True)

hoProduct :: [Int] -> Int
hoProduct = foldr (*) 1

hoMap :: (a -> b) -> [a] -> [b]
hoMap f = foldr ((:) . f) []

-- hoFuncList :: [(a -> b)] -> a -> [b]
-- hoFuncList x = foldr (\x acc -> (:) . x) []

rElem :: (Eq a) => a -> [a] -> Bool
rElem n [] = False
rElem n (x:xs)
    | n == x = True
    | otherwise = rElem n xs

rDouble :: [Int] -> [Int]
rDouble [] = []
rDouble (x:xs) = (2 * x) : rDouble xs

rFactors :: Int -> [Int]
rFactors x = x : something (x-1)
    where something f
            | f == 0 = []
            | x `mod` f == 0 = f : something (f -1)
            | otherwise = something (f-1)

rRemoveLower :: String -> String
rRemoveLower [] = []
rRemoveLower (x:xs)
    | x `elem` ['A'..'Z'] = x : rRemoveLower xs
    | otherwise = rRemoveLower xs

rProduct :: [Int] -> Int
rProduct [] = 1
rProduct (x:xs) = x * rProduct xs

rSort :: (Ord a) => [a] -> [a]
rSort [] = []
rSort (x:xs) = 
    let lower = rSort[a | a <- xs, a <= x  ]
        higher = rSort[a | a <- xs, a >x]
    in lower ++ [x] ++ higher

rMap :: (a -> b) -> [a] -> [b]
rMap _ [] = []
rMap f (x:xs) = (f x) : rMap f xs

rFilter :: (a -> Bool) -> [a] -> [a]
rFilter _ [] = []
rFilter f (x:xs)
    | f x == True = x : rFilter f xs
    | otherwise = rFilter f xs

rZip :: [a] -> [b] -> [(a,b)]
rZip _ [] = []
rZip [] _ = []
rZip (x:xs) (y:ys) = (x,y) : rZip xs ys

rZipWith :: (a -> a -> b) -> [a] -> [a] -> [b]
rZipWith _ [] _ = []
rZipWith _ _ [] = []
rZipWith f (x:xs) (y:ys) = (f x y) : rZipWith f xs ys

rFuncList :: [(a -> b)] -> a -> [b]
rFuncList [] _ = []
rFuncList (f:fs) x = (f x) : rFuncList fs x

rQuickCheck :: [a] -> (a -> Bool) -> Bool
rQuickCheck [] _ = True
rQuickCheck (x:xs) p
    | p x == True = rQuickCheck xs p
    | otherwise = False

-- Higher Order Functions
-- ===========================

-- A higher-order function is a function that takes other functions as an argument,
-- or returns a function as a result.

-- "Pure" Programming Language
-- ============================

-- A Language that guarantees the (weak) equivalence of call-by-name, call-by-value,
-- and call-by-need evaluation strategies

-- "Lazy" Programming Language
-- ===============================

-- Also called call-by-need, an evaluation stategy that delays the evaluation of an expression
-- until it's value is needed, which also avoids repeated evaluations.

-- Type Inference
-- ============================

-- The Automatic deduction of the datatype of an expression.

-- Lambda Abstraction
-- ===============================

-- An anonymous function. It gets its name from the notation used writing it '\'

-- "cons" operator
-- =====================

-- in Haskell, cons function will add something to the front of a list to the same effect of :[]

-- definition
-- ==============================
-- When one first specifies the input and output types of a function, then
-- writes the function itself under it.

-- Pattern Matching
-- ==============================
-- A way to determine the outputs of a function by processing the inputs of a function
-- differently

-- Curried Functions
-- =============================
-- To curry a function is to take a function that requires multiple arguments and only 
-- passing in 1, such that it returns another function that then requires a single 
-- argument to produce the desired output

-- Function Composition
-- ===============================
-- The act of pipelining the result of 1 function into the input of another.

-- Modules
-- ================================
-- A modules in Haskell serves the dual purpose of controlling name-spaces and creating
-- abstract data types

-- Tail recursion
-- =================================
-- A recursive pattern in which the final result of the resursive call is the 
-- final result of the function itself.

-- Predicate
-- ==================================
-- An expression that evaluates to True or False used to process List