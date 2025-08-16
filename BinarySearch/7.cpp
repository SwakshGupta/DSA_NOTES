/*
Binary search 


Find the square root of an integer 

one of the way through linear serach is 

for(int i=1; i<=n; i++)
{
    if(i*i<=n)
    {
        ans=i;
    }
    else
    {
        break;  // so our loop will break if the first condition is not met 
    }
}



*/


#include<iostream>
using namespace std;

// lets do this problem via binary search 

int sq(int n)
{
int l=0;
int h=n;
int ans=-1;

while(l<=h)
{
int mid=(l+h)/2;


if(mid*mid<=n)
{
    ans=mid;
    l=mid+1;

}

else if(mid*mid>n)
{
    h=mid-1;
}
}


return ans;

}


int main()
{




    return 0;
}