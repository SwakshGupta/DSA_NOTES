// so we are given with an array  which has duplicate elemetns in it with 2 elements repleating once return those 

#include<iostream>
using namespace std;


vector<int>solve(vector<int>nums)
{
    int ans=0;
    long rightmost=0;  // (ans-1 in the lower case will give us error if ans=-2^31)

for(int i=0; i<nums.size(); i++)
{

ans=ans^nums[i];   //  here we are taking xor of every element 

rightmost=(ans&ans-1)^ans; // this will return us  the only bit which is different in both the unique of the nums 

// now we know the differentiating element we will seperate them both from nums 
}

int  b1=0,b2=0; // here we have created two sepearate buckets to differentiate with the number 

for(int i=0; i<nums.size(); i++)
{

    // herer we will divide the nums  into to categroy based on the  position where i is set 

    if(nums[i]&rightmost) // this is equal to 1 then put this in one bucket and xor it repetetions will cancel out and you will get one 
    {
        b1=b1^nums[i];
    }
else
{
    b2=b2^nums[i]; // if  it is equal to zero then xor other set of numbers and you will get the answer 
}




}
return {b1,b2};

}






int main()
{





    return 0;
}



