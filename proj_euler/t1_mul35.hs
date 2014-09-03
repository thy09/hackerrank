main = do
    count <- getLine
    lines <- getLines (read count)
    let nums = map (\l -> read l :: Int) lines
    mapM_ (\num -> print (mAorB (num - 1) 3 5)) nums

getLines :: Int -> IO [String]
getLines count = do
  sequence (replicate count getLine)
  
mAorB :: Int -> Int -> Int -> Int
mAorB num a b = 
	let lcmab = lcm a b
	in (divsum num a) - (divsum num lcmab) + (divsum num b)

divsum :: Int -> Int -> Int
divsum num k = 
	let d = num `div` k
	in ((1+d)*d `div` 2)*k