
--27
mymap f [] = []
mymap f (x:xs) = [f x] ++ mymap f xs 

--30

myinits [] = [[]]
myinits xs =  myinits (init xs) ++ [xs]

--32

partitionc :: [a] -> [([a],[a])]
partitionc [] =[([],[])]
partitionc (x:xs) = divide [x] xs 
divide ys [] = [(ys,[])]
divide ys zs = [(ys,zs)] ++ divide (ys ++ [head zs]) (tail zs) 

-- 33

nondec :: Ord(a) => [a] -> Bool

nondec (x:xs)   
    |xs == [] = True
    |x <= head xs = nondec xs
    |otherwise = False

-- 34

myzip :: [a] -> [a] -> [(a,a)]
myzip [] ys = []
myzip xs [] = []
myzip (x:xs) (y:ys) = [(x,y)] ++ myzip xs ys

-- 35

permutations :: [a] -> [[a]]

-- sum - sumuje 
--product - mnoży
--any - czy jeden w liscie spełnia warunek 
--all czy wszytkie w liscie spełniają warunek 