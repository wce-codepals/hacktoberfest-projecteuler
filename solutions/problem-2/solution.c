#include <stdio.h>
int main(void)
{
  unsigned int zx1 = 1, zx2 = 1, zx3 = 2, zsum = 0;
  while (zx3 < 4000000)
 {
    zx3 = zx1 + zx2;
    zsum += zx3 * !(zx3%2);
    zx1 = zx2;
    zx2 = zx3;
  }
  printf("%u\n", zsum);
  return 0;
}
