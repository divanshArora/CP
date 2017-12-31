// C++ program to find modular inverse of a under modulo m
// This program works only if m is prime.
#include<iostream>
#define intx long long
using namespace std;
 
// To find GCD of a and b
intx gcd(intx a, intx b);
 
// To compute x raised to power y under modulo m
intx power(intx x, unsigned intx y, unsigned intx m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(intx a, intx m)
{
    intx g = gcd(a, m);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m);
    }
}
 
// To compute x^y under modulo m
intx power(intx x, unsigned intx y, unsigned intx m)
{
    if (y == 0)
        return 1;
    intx p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}
 
// Function to return gcd of a and b
intx gcd(intx a, intx b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
// Driver Program
int main()
{
    intx a = 2, m = 1000000007;
    modInverse(a, m);
    return 0;
}