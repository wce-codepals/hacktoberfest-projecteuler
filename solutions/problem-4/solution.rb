(100..999).to_a.repeated_combination(2).map { |x, y| x * y }.select do |x|
  x.to_s == x.to_s.reverse
end.max

# 906609
