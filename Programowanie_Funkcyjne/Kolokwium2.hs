
--Zdanie 1
lenght'  :: Floating a => [b] -> a
lenght' xs = foldl (\acc x -> acc + 1.0) 0.0 xs 

sredniaF :: Floating a => [a] -> a
sredniaF xs =  (foldl (\acc x -> acc + x) 0.0 xs) / (lenght' xs)

varF :: Floating a => [a] -> a
varF xs = (foldl (\acc x -> acc+ ((x-(sredniaF xs))^2)) 0 xs ) / (lenght' xs)

sredniaM :: Floating a => [[a]] -> a
sredniaM xs = (foldl (\acc x -> acc + x) 0 (map varF xs)) / (lenght' xs)

varM :: Floating a => [[a]] -> a
varM xs = (foldl (\acc x -> acc+ ((x-(sredniaF xs))^2)) 0 xs / (lenght' xs)
    let xs = map sredniaF xs

--Zadanie 2
lewy' :: (Integral b, Floating a) => a -> [a] -> b -> [a]
lewy' _ [] _ = []
lewy' x (a:as) y = [a*x^y] ++ (lewy' x as (y+1))

lewy :: Floating a =>a -> [a] -> a
lewy x as = foldl (\acc x -> acc + x ) 0 (lewy' x as 1) 

-- let a = 