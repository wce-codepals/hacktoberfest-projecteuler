def multiples_of_three_and_five():
  sm = 0
  for i in range(1000):
    if i % 3 == 0 or i % 5 == 0:
      sm += i
  return sm

def main():
  s = multiples_of_three_and_five()
  print(s)


main()