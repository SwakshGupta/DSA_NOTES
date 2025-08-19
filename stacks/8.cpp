
/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.


approach is given in the notebook one is the  brute force which computes the nse and pse and the other is using the stack which is the optimal approach 


 So in the largest area histogram there are two approaches one is finding the nse and pse seperatly lets discuss that

1. so we will find the nse and pse seperately which will give us the range (nse-pse-1) is the range *heights[i] will give the area 

   maxi=max(maxi,nums[i]*(nse-pse-1));



*/




#include<iostream>
#include<stack>;
using namespace std;

int LargestArea(vector<int>nums)
{
stack<int>st;
int maxArea=0;
int n=nums.size();

for(int i=0; i<n; i++)
{
while(!st.empty() && nums[st.top()]>nums[i]) // so we  have created a stack and we will find area  of each index while we are popping out the elements (logic is there in the notebook)
{
   int  element=st.top();
        st.pop();
        int nse=i;
         int pse=st.empty() ?-1:st.top();

         maxArea=max(nums[element]*(nse-pse-1),maxArea);
}
}
// if there are leftover elements even when the array is traversed then we will do this (explanation in the notes )

while(!st.empty())
{
    int nse=n;
    int element=st.top();
    st.pop();
    int pse=st.empty()?-1 :st.top();

    maxArea=max(maxArea,(nse-pse-1)*nums[element]);

}
return maxArea;




}


int main()
{





    return 0;
}