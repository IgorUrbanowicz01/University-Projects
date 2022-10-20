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