/*
 1. we know how to swap a variable using a temp variable but what if you can't use third variable  then we will use xor operator 


2. Check if ith bit is set or not  (set names whether that bit is one or not if it is then return 1 value and if it is not then return zero value )

we can do this by converting the number to its binary equivalent  but here we will do it by  using bitwise operator 

why we are doing bitwise operation cuz they are much much faster


*/





#include<iostream>
using namespace std;

int swap(int a,int b)
{

a=a^b;
b=a^b;
a=a^b;  // logic in notebok 

}


// other qestions/concepts are given in the notebook 


int main()
{




    return 0;
}