
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

myzip :: [a] -> [b] -> [(a,b)]
myzip [] _ = []
myzip _ [] = []
myzip (x:xs) (y:ys) = [(x,y)]++ myzip xs ys

-- 35

--permutations' :: [a] -> [[a]]

--permutations' [] = []
--permutations' xs    |lenght xs  <= 3 = cycle (lenght xs) xs
--                    |groupInto 3 xs 


--37

qs1 [] = []
qs1 (x:xs) = qs1 [t|t<- xs,t<=x]++[x] ++ qs1 [t|t<-xs,t>x]

qs2 [] = []
qs2 [x] = [x]
qs2 [x,y]   |y<x = [y,x]
            |otherwise = [x,y]
            
qs2 (x:xs) = qs2 [t|t<- xs,t<=x] ++ [x] ++ qs2 [t|t<-xs,t>x]

--39
-- sum - sumuje 
--product - mnoży
--any - czy jeden w liscie spełnia warunek 
--all czy wszytkie w liscie spełniają warunek 

-- 40


-- 41 

leven' a b  | mod a 2 == 0 = b+1 
            | otherwise = b
                --in foldr even' 0 [1,2,3,4,5,6]


-- 42

nondecrec (x:xs)   
    |xs == [] = True
    |x <= head xs = nondecrec xs
    |otherwise = False

nondec' (x:xs)  = zip xs (tail xs)

-- 44


ssmf a b| a>b = [a]
        | otherwise = []