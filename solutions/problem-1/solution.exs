multiples = fn(n) -> (rem(n, 3) == 0) || (rem(n, 5) == 0 ) end

1..999 
|> Enum.filter(multiples) 
|> Enum.sum
|> IO.puts
