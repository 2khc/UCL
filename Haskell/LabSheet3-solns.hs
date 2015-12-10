-- LabSheet3-solns.hs

mult :: Num a => [a] -> a
mult = foldr (*) 1 

posList :: [Int] -> [Int]
posList = filter (\x -> x > 0)

trueList :: [Bool] -> Bool
trueList = foldr (&&) True

evenList :: [Int] -> Bool
evenList = foldr ((&&) . even) True

maxList :: Ord a => [a] -> a
maxList xs = foldr max (head xs) xs


inRange :: Int -> Int -> [Int] -> [Int]
inRange n m xs = filter (\x->(x>= n) && (x<= m)) xs

countPositives :: [Int] -> Int
countPositives xs = foldr (+) 0 (map (\x->1) (filter (\x-> x>0) xs))

myLength :: [a] -> Int
myLength xs = foldr (+) 0 (map (\x -> 1) xs) 

myMap :: (a -> b) -> [a] -> [b]
myMap f = foldr ((:).f) [ ]

myLength' :: [a] -> Int
myLength' xs =  foldr (+) 0 ( map' (\x-> 1) xs)
          where map' f = foldr ((:).f) [ ]



