#include <math.h>
#include <iostream>
#include <chrono>

using namespace std;

int TR_triangle(int n)
{
    return ((n + 1) * n) / 2;
}

// Math fact: a prime decomposition n = Prod_i p_i^e_i yields
// Prod_i (e_i + 1) different divisors
int TR_num_divisors(int n)
{
    auto divisors = 1;  // 1 has one divisor
    {
        auto f = 2;
        auto count = 0;
        while (n % f == 0) {
            ++count;
            n /= f;     // divide by factor of 2
        }
        divisors *= (count + 1);
    }

    // <= n guarantees that a prime has 2 divisors
    for (auto f = 3; f <= n; f += 2) {
        auto count = 0;
        while (n % f == 0) {
            ++count;
            n /= f;     // divide by odd factor
        }
        divisors *= (count + 1);
    }
    return divisors;
}

int TR_unique_divisors(int n)
{
    if (n % 2 == 0)
        n /= 2;
    return TR_num_divisors(n);
}

// triangle(n) = (n + 1) * n / 2
// only one of them has a factor of two, and they have no prime factors in common
// we can cache one of the divisor counts while iterating over triangle numbers
int TR_first_triangle_with_more_than_n_divisors(int n)
{
    auto i = 1;
    for (auto f1 = TR_unique_divisors(i), f2 = TR_unique_divisors(i + 1); f1 * f2 <= n; ++i)   {
        f1 = f2;                        // re-use result from previous iteration
        f2 = TR_unique_divisors(i + 2);    // only one new computation
    }
    return i;
}
int* TIN_ESieve(int upperLimit)
{
    int sieveBound = (int)(upperLimit - 1) / 2;
    int upperSqrt = (int)((sqrt((double)upperLimit) - 1) / 2);
    bool PrimeBits[1000] = {false};
    int* numbers = new int[1000];
    int index = 0;
    for(int i = 2; i <= upperSqrt; i++)
    {
        if(!PrimeBits[i])
        {
            for(int j = i * i; j <= sieveBound; j += i)
            {
                PrimeBits[j] = true;
            }
            numbers[index++] = i;
        }
    }
    for(int i = upperSqrt + 1; i <= sieveBound; i++)
    {
        if(!PrimeBits[i])
        {
            numbers[index++] = i;
        }
    }
    numbers[index] = 0;
    return numbers;
}
int TIN_PrimeFactorisationNoD(int number, int primelist[])
{
    int nod = 1;
    int exponent;
    int remain = number;

    for(int i = 0; primelist[i] != 0; i++)
    {

        // In case there is a remainder this is a prime factor as well
        // The exponent of that factor is 1
        if(primelist[i] * primelist[i] > number)
        {
            return nod * 2;
        }

        exponent = 1;
        while(remain % primelist[i] == 0)
        {
            exponent++;
            remain = remain / primelist[i];
        }
        nod *= exponent;

        //If there is no remainder, return the count
        if(remain == 1)
        {
            return nod;
        }
    }
    return nod;
}
int main()
{
    auto start = chrono::steady_clock::now();
    for(int c1 = 1; c1 <=10; c1++)
    {
        auto sieve = TIN_ESieve(1000);
        int i1 = 2;
        int cnt = 0;
        int Dn1 = 2;
        int Dn = 2;
        while(cnt < 500)
        {
            if(i1 % 2 == 0)
            {
                Dn = TIN_PrimeFactorisationNoD(i1 + 1, sieve);
            }
            else
            {
                Dn1 = TIN_PrimeFactorisationNoD((i1 + 1) / 2, sieve);
            }
            cnt = Dn * Dn1;
            i1++;
        }
        if(c1 == 1)
            cout << "the first Triangle number to have over " << 500 << " divisors : " << i1 * (i1 - 1) / 2 << "\n";
    }
    auto stop = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::milliseconds>((stop - start)/10);

    cout << "\nUsing TIN methods it averaged " << elapsed.count() << " milliseconds." << "\n\n";
    start = chrono::steady_clock::now();
    for(int c2 = 1; c2 <= 10; c2++)
    {
        auto const n = 500;
        auto res = TR_triangle(TR_first_triangle_with_more_than_n_divisors(n));
        if(c2 == 1)
            std::cout << "the first Triangle number to have over " << n << " divisors : " << res << "\n";
    }
    stop = chrono::steady_clock::now();
    elapsed = chrono::duration_cast<std::chrono::milliseconds>((stop - start) /10);

    cout << "\nUsing TR methods it averaged " << elapsed.count() << " milliseconds." << "\n";
    return 0;
}