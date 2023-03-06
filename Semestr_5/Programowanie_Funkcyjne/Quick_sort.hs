qs [] = []
qs (x:xs) = qs [t|t<- xs,t<=x]++[x] ++ qs [t|t<-xs,t>x]

qs02 [] = []
qs02 (x:xs) = left ++[x] ++ right
  where left  = qs02 [t|t<- xs,t<=x]
        right = qs02 [t|t<-xs,t>x]

qs03 [] = []
qs03 (x:xs) = let left  = qs03 [t|t<- xs,t<=x]
                  right = qs03 [t|t<-xs,t>x]
              in left ++[x] ++ right