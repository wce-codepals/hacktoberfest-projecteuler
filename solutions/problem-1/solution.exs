import Enum, only: [filter: 2, sum: 1]
numbers = 1..999
filter(numbers, fn(x) -> (rem x, 3) == 0 or (rem x, 5) == 0 end )
|> sum
|> IO.puts
