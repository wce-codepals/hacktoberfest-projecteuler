#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

#define SIEVE_RANGE (150)
#define PRIME_COUNT (16)

inline long long Norm(long long a)
{
    return (a < 0) ? -a : a;
}

// -----------------------------------------------------------------------------

bool sieve_visited[SIEVE_RANGE] = {};
long long primes[PRIME_COUNT] = {};

void Sieve()
{
    int curr_pos = 0;
    for (long long i = 2; i < SIEVE_RANGE; i++)
    {
        if (!sieve_visited[i])
        {
            if (i % 4 == 1)
            {
                primes[curr_pos] = i;
                curr_pos++;
            }
            for (long long j = i + i; j < SIEVE_RANGE; j += i)
            {
                sieve_visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

typedef std::pair<long long, long long> Solution;
typedef std::vector<Solution> SolutionSet;

std::map<long long, Solution> primitive_solutions;
std::map<long long, SolutionSet> solutions;
long long sums[1 << PRIME_COUNT] = {};

void SetPrimitiveSolution(long long n)
{
    long long sum;
    for (long long a = 1; 2*a*a <= n; a++)
    {
        for (long long b = a; ; b++)
        {
            sum = a*a+b*b;
            if (sum > n)
            {
                break;
            }
            if (sum == n)
            {
                primitive_solutions[n].first = a;
                primitive_solutions[n].second = b;
                return;
            }
        }
    }
}

void InitPrimitiveSolutions()
{
    for (int i = 0; i < PRIME_COUNT; i++)
    {
        SetPrimitiveSolution(primes[i]);
    }
}

SolutionSet MakeSolutionSet(const SolutionSet& s, const SolutionSet& t)
{
    if (s.size() == 0)
    {
        return t;
    }
    if (t.size() == 0)
    {
        return s;
    }
    SolutionSet rv;
    long long a, b, temp;
    for (SolutionSet::const_iterator i = s.begin(); i != s.end(); i++)
    {
        for (SolutionSet::const_iterator j = t.begin(); j != t.end(); j++)
        {
            a = Norm(i->first * j->second - i->second * j->first);
            b = Norm(i->first * j->first + i->second * j->second);
            if (a > b)
            {
                temp = a;
                a = b;
                b = temp;
            }
            rv.push_back(std::make_pair(a, b));
            a = Norm(i->first * j->first - i->second * j->second);
            b = Norm(i->first * j->second + i->second * j->first);
            if (a > b)
            {
                temp = a;
                a = b;
                b = temp;
            }
            rv.push_back(std::make_pair(a, b));
        }
    }
    return rv;
}

void SetSum(long long n)
{
    for (SolutionSet::const_iterator it = solutions[n].begin();
        it != solutions[n].end(); it++)
    {
        sums[n] += it->first;
    }
}

void Solve()
{
    for (int i = 0; i < PRIME_COUNT; i++)
    {
        solutions[1 << i].push_back(primitive_solutions[primes[i]]);
        SetSum(1 << i);
    }
    for (int i = 1; i < (1 << PRIME_COUNT); i++)
    {
        if (sums[i])
        {
            continue;
        }
        for (int j = 0; j < PRIME_COUNT; j++)
        {
            if ((1 << j) & i)
            {
                solutions[i] = MakeSolutionSet(solutions[i - (1 << j)], solutions[1 << j]);
                SetSum(i);
                break;
            }
        }
    }
}

long long GetSigmaOfSums()
{
    long long rv = 0;
    for (int i = 1; i < (1 << PRIME_COUNT); i++)
    {
        rv += sums[i];
    }
    return rv;
}

int main(int argc, char* argv[])
{
    Sieve();
    InitPrimitiveSolutions();
    Solve();
    std::cout << GetSigmaOfSums() << std::endl;
    return 0;
}
