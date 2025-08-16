/*
Next Greater element 


so in this next greater element we have three conditions 

1. If the stack is empty then the next greater element is -1;

2. if the stack is not empty then and top element is greater than the current element then the top element is the 
next greater element 

3. if the stack is not empty and the top elemetn is lesser than the current element then we will start popping the 
stack till we find a greater element or if the stack is  becomes empty and then we will return -1 ;




*/


#include<iostream>
#include<stack>
using namespace std;


vector<int> nextGreaterElement(vector<int>& arr, int n) {
    stack<int> s;
    vector<int> ans(n);
    
    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while(!s.empty() && s.top() <= curr) { // if the curr element is greater than the stack top then we have to pop that element until a greater element is not found 
            s.pop();
        }
        ans[i] = (s.empty() ? -1 : s.top()); // if stack is empty then return -1 otherwise return the top element in NGE array 

        s.push(curr); // push the current element to the stack 
    }
    return ans;
}

int main()
{


    return 0;
}




/*

vector<int>solve(vector<int>nums,int n)
{

stack<int>s;
vector<int>ans;

for(int i=n-1; i>=0; i++)
{
    int curr=nums[i];

    while(!s.empty() && curr>s.top())
    {
        s.pop();
    }
    
    ans[i]=s.empty()?-1:s.top();


}






}






*/