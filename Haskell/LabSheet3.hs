mult :: [Int] -> Int
mult xs = foldr (*) 1 xs

posList :: [Int] -> [Int]
posList = filter (\x -> x >= 0) 

trueList :: [Bool] -> Bool
trueList = foldr (\x acc-> if x == True && acc == True then True else False) True

-- need zero check
evenList :: [Int] -> Bool
evenList = foldr (\x acc -> if x `mod` 2 == 0 && acc == True then True else False) True

maxList :: (Ord a) => [a] -> a
maxList = foldr1 (\x acc -> if x > acc then x else acc)

inRange :: Int -> Int -> [Int] -> [Int]
inRange a b xs = filter (<=b) . filter (>=a) $ xs
    
countPositives :: [Int] -> Int
countPositives = length . filter (\x -> x >= 0)

myLength :: [a] -> Int
myLength  xs = foldr (\x acc -> if x == 1 then acc + 1 else acc) 0 . setToZero $ xs
    where setToZero [] = []
          setToZero (x:xs) = 1 : setToZero xs

myMap :: (a -> b) -> [a] -> [b]
myMap f xs = foldr(\x acc ->acc + f x )[] xs
   