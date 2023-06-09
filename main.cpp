#include <iostream>
#include <cmath>


bool isPrime(long long num);
long long endTest;


int main ()
{
    long long q {0}, i;
    for (i = 0; i <= 10000000; i++)
    {
        if (isPrime(i))
        {
            q++;
        }
    }
    std::cout << q << std::endl;
    return 0;
}


bool isPrime(long long num)
{
    endTest = (long long) std::floor(std::pow(num, .5));

    if (num <= 7)
    {
        switch (num)
        {
            case 2: return true;
            case 3: return true;
            case 5: return true;
            case 7: return true;
            default: return false;
        }
    }
    else if (num > 7)
    {
        if (num % 2 == 0) return false;
        else if (num % 3 == 0) return false;
        else if (num % 5 == 0) return false;
        else if (num % 7 == 0) return false;
        if (num > 11)
        {
            unsigned short int jumpfive { 3 };
            long long i;
            for (i = 11; i < num; i += 2)
            {
                if (jumpfive++ == 5)
                {
                    jumpfive = 1;
                    continue;
                }
                if (i > endTest) break;
                if (num % i == 0 ) return false;
            }
        }
        return true;
    }
    return false;
}