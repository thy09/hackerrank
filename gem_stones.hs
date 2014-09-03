main = do  
    count <- getLine
    lines <- getLines (read count)
    let ulines = map unique lines
    let ans = foldl1 (\s1 s2 -> [c| c<-s1,c `elem` s2]) ulines
    print (length ans)

getLines :: Int -> IO [String]
getLines count = do
  sequence (take count (repeat getLine))

unique :: [Char] -> [Char]
unique [] = []
unique (x:xs) = [x] ++ [y | y <- (unique xs),x /= y]

getIdx :: [Char] -> Char -> Int
getIdx [] c = -1
getIdx (x:xs) c = if (x == c) then 0 
  else 
    if (xs_idx /= -1) then ( 1 + xs_idx)
    else -1
    where xs_idx = (getIdx xs c) 

splitLines :: [Char] -> [[Char]]
splitLines xs = 
    let idx = getIdx xs '\n'
    in  if (idx == -1)
          then [xs] 
          else [take idx xs] ++ (splitLines (drop (idx+1) xs))