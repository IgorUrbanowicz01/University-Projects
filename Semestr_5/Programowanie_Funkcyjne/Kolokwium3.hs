data BTree a = L a | N a (BTree a) (BTree a)

mytree = N 8 (N 10 (L 1) (L 2)) (L 5)

instance Eq a => Eq (BTree a) where
    L x /= L y = False
    L x == L y = True
    N x a1 a2 == N y b1 b2 = (x == y) && a1 == b1 && a2 == b2 

instance Show a => Show (BTree a) where
  show (L x)     = show x
  show (N a lt rt) =  "<" ++ show lt ++ " ." ++ show a ++ ". "++ show rt ++ ">"


instance Functor BTree where
    fmap f (L a) = L (f a)
    fmap f (N x a1 a2) =  N (f x) (fmap f a1) (fmap f a2)

  --  *Main> fmap (^2) mytree 
-- <<1 .100. 4> .64. 25>

oldTree :: Num t => (t -> t -> t -> t) -> t -> BTree t -> t
oldTree f z (L a) = z + a
oldTree f z (N x a1 a2) = z + f x (oldTree f z a1) (oldTree f z a2) 

sumFTree :: Num t => t -> t -> t -> t
sumFTree x1 x2 x3 =  x1 + x2 + x3   

sumFTree2 :: Num t => t -> t -> t -> t
sumFTree2 x1 x2 x3 =  (x1^2) + x2 + x3   


--coś w tym stylu 
