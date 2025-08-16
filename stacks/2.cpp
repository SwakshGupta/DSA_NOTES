/*

Next greater prblem 2  here we can select the elements in circular manner 


here we are  duplicating the array and just making a imafinary array next to the original array 




algorithm

1.  start traversing from right to left from 2N-1 to 0

2.  we will start pushing to the answer array when our i<N before that we will be building our queue only

3. if stack is empty then just push ans[i%N] we will be taking advantage of modulo operator 

4. if the stack is not empty and  if  ans[i%N] is greater than the top element then pop the element 





*/
#include<iostream>
#include<stack>
using namespace std;

vector<int>NGE(vector<int>nums)
{
vector<int>ans;
stack<int>s;
int n=nums.size();

for(int i=2*n-1; i>=0; i--) // we will be traversing from 2n-1 to 0
{
while(!s.empty() && s.top()<=nums[i%n])
{
s.pop();
}

if(i<n) // then only we start looking for the NGE 
{
    ans[i]=s.empty()? -1:s.top();
}
s.push(nums[i%n]);  // the code is similar to the previous we have just added this condition of (i<n) since only want to find NGE of first half of the array  

}
return ans;
}

int main()
{




    return 0;
}

// here the time complexity is o(4n) and space complexity of o(2n)