/*
Given an integer n, return the number of prime numbers that are strictly less than n

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; ++i) { // checking till sqrt(n)
        if (n % i == 0) {
            return false; // found a divisor, not prime
        }
    }

    return true; // no divisors found, it's prime
}

This is how we check whether  a number is prime 



Better appraoch:

1. Written in the notebook write in the code by yourself

*/







#include<iostream>
using namespace std;

int main()
{




    return 0;
}