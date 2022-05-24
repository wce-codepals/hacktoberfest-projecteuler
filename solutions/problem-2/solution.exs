# Solution #2

defmodule Fibonacci do
  def sum_sequence(a, _b, n) when a >= 4000000, do: IO.inspect n
  def sum_sequence(a, b, n) when rem(a, 2) == 0, do: sum_sequence(b, a + b, n + a)
  def sum_sequence(a, b, n), do: sum_sequence(b, a + b, n)
end

Fibonacci.sum_sequence(1,2,0)
