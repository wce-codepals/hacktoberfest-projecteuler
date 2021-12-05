
#include <iostream>

// return true if root^2 matches 1_2_3_4_5_6_7_8_9_0
bool match(unsigned long long x)
{
  unsigned long long square = x * x;

  // required digits in reverse order
  const unsigned int Right2Left[] = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  unsigned int index = 0;

  // check all digits
  do
  {
    // right-most digits matches current element of Right2Left ?
    auto digit = square % 10;
    if (digit != Right2Left[index++])
      return false;

    // remove the digit which passes the test and skip the next digit which is unknown, too
    square /= 100;
  } while (square > 0);

  // all tests passed !
  return true;
}

int main()
{
  // smallest possible number: gaps are zeros => sqrt(1020304050607080900)
  const unsigned int MinNumber = 1010101010;
  // largest  possible number: gaps are nines => sqrt(1929394959697989990)
  const unsigned int MaxNumber = 1389026620;

  //for (unsigned int x = MinNumber; x <= MaxNumber; x += 10)
  for (unsigned int x = MaxNumber; x >= MinNumber; x -= 10)
    if (match(x))
    {
      std::cout << x << std::endl;
      break;
    }

  return 0;
}
