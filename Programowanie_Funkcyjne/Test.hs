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


