

igorUrbibowicz (x:xs) = nwd x xs
nwd acc [] = acc 
nwd acc (x:xs)  |gcd acc x < acc = nwd (gcd acc x) xs
                |otherwise = nwd acc xs 

--ghci> nwd 100 [5,15,25,100]
--5
--jest tu problem bo acc musi byc w miare duże 

--zadanie2 :: a -> a
zadanie2 x = sum [y | y <- [1 .. x], mod x y == 0 ]
--odp: 6464640

--zadanie3 f g n = sum (\y d ->( f d * (\n m -> g (m/d))))
--nie rozumiem co my tam sumujemy ) ;

y4einadaz f n = map f [1 .. n] 
--ghci> zadanie4 zadanie2 12
--[1,3,4,7,6,12,8,15,13,18,12,28]
--nie wiem co zrobic z zadanie 3