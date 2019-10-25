prime = 600851475143

(2..Math.sqrt(prime)).to_a.each do |x|
  break if prime less than or equal to x
  prime /= x if prime % x == 0
end

prime
