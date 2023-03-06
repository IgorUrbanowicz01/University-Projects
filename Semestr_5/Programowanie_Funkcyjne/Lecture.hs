import Prelude

filter' sx = [x| x<-sx, odd x] 

--filter'' p(x:xs)
--   |px = x:filter'' xs
--   |otherwise = filter''

elem' x [] = False
else' x(y:ys) = if(x==y) then True else elem' x ys

zip' _[] = []
zip' []_ = []
zip' (x:xs)(y:ys) = (x,y):zip' xs ys

zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = (f x y):zipWith' f xs ys

yy = [1,3..]::[Integer]
--take 6
fib = 0:1:zipWith (+) fib (tail fib)

--spłaszczanie

foldr' _ e [] = e
foldr' f e (x:xs)= f x (foldr' f e xs)

lenght' xs = foldr'(\x n -> n+1) 0 xs

and' xs= foldr'(&&) True xs 
or' xs= foldr'(||) False xs 

reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

reverse'' xs = foldr' (\x xs -> xs ++ [x]) [] xs 

foldl' _ e [] = e
foldl' f e (x:xs) = foldl' f (f e x) xs  

reverse''' xs = foldl' (flip(:)) [] xs 

--[\x ->x^2, \X->x*10]<*>[1..5]

--((\x ->(sqrt x)).(\x ->(1/x))) (-1)
--NaN
