import Data.List

fact03 n | n<=0 = 1
         | otherwise = n * fact03 (n-1)

fact01 n = if n == 0 then 1 else n * fact01 (n-1)

fact02 0 = 1
fact02 n = n * fact02 (n-1)

doubleSmallNumbers x = if x>100
                    then x
                    else x*2

makesEvenNumbers y = [x*2 | x<- [1..y]]

makesNumbersDiv3 y = [x | x<- [1..y],mod x 3 == 0]

pushIfEven xs = [if x < 10 then "Push" else "Pull" | x <- xs, odd x ]

removeNonUppercase:: [Char] -> [Char]
removeNonUppercase x = [xs | xs <- x ,elem xs ['A' .. 'Z']]

productFromOneToX x = product [1 .. x]

addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 +y2)

-- cycle[1,2,3]
--repeat 5

--fst first of tuplet
--second of tuplet

--let triangels = [ (a,b,c) | c<-[1..10], b<-[1..10], a<-[1..10], a^2 + b^2 == c^2]

calcBmis :: (RealFloat a) => [(a, a)] -> [a]  
calcBmis xs = [bmi w h | (w, h) <- xs]  
    where bmi weight height = weight / height ^ 2  


addTree :: Int -> Int -> Int -> Int
addTree x y z = x + y + z

--Int - 32 bit whole numbers
--Intiger aka Big Int
--Float sigle presition point 
--Double double presition poit
--Bool True False 
--char character


--(==) :: Eq a => a -> a -> Bool
--Eq a class constrain

--CLASS CONSTRAIN:
--Eq - są porównywalne
--Ord - można je porównywaać GT, LT, EQ (must be a meber of Eq)
--Show - mozna jet pokazać jako string 
--Read - można wziąść string i zamienić go na typ:
--Enum - są pokolei numerowane maja succ i pred 
--Num - enything taht can act like a number

--(5::Int)*(6::Intiger)

--read "5.2" :: Float

--Lambdas:

--numLongChains ::  Int 
--numLongChains f = length (filter (\xs -> length xs > 15) (map f [1..100]))

-- map (\x -> x+3)[1..100] = map (+3) [1..100]

--newZip :: [a] -> [b] -> [c]
newZip xs ys = zipWith (\a b -> (a * 30 + 3) / b) xs ys
mapingTupltets :: Num a => [(a,a)] -> [a]
mapingTupltets xs = map (\(a,b) -> a+b) xs


flip' :: (a -> b -> c) -> b -> a -> c
flip' f = \x y -> f y x 

sum''' xs = foldr (\acc x -> acc + x) 0 xs

permF [] = []
permF (x:xs) = [x] ++ xs ++ permF xs 

sumF n = foldl (\x y -> x + 1/y^2) 0 [1..n+1] 

map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc ) [] xs

-- map ($ 3) [(4+), (10*), (^2), sqrt]

hetman x = hetman' [x] 
hetman' xs (y:ys)
        | lenght xs == 8 = xs
        | y == (not(elem x xs) &&  not(elem x (temp (reverse xs))) && not(elem x (temp' (reverse xs)))) hetman' xs++[y] ys
        | otherwise = []

temp [] = []
temp (x:xs) = (x-1) : temp (map (\z -> z-1) xs)

temp' [] = []
temp' (x:xs) = (x+1) : temp' (map (\z -> z + 1) xs)  


sqrt; a = sqrt'' a a
sqrt'' a x = sqrt' a (\x -> div (x +div 2 a) 2)