# Solution #6

IO.inspect (
  :math.pow(1..100 |> Enum.reduce(&(&1 + &2)), 2)) - (1..100 |> Enum.reduce(&((&1 * &1) + &2))
)
