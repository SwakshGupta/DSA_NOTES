/*

Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

Examples

Example 1:
Example 1: 

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.


*/

#include<iostream>
using namespace std;


// this was  more like of brute force solution 

vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr) // this is our 2d array contains all the other elements 
{

int n=arr.size();
sort(arr.begin(),arr.end()); // so we have to sort the array first so that we wont miss any other overlapping problems
vector<vector<int>>ans;

for(int i=0; i<n; i++) 
{
    int start=arr[i][0]; // these are the indices of the element in the array 
    int end=arr[i][1];

    if(!ans.empty() && end<=ans.back()[1]) // if our ans array is not empty and and end is less than the second of back so we dont need to check it so continue

    // in notes if the interval was [2,4] and ans which is already there was [1,6]  since 4<6 so we dont have to check for this case so continue
     {
        continue; // means increment the value of i 
     }

for(int j=i+1; j<n; j++ )
{
    if(arr[j][0]<=end)  // if the first element of interval is less than end of first it means it is a overlapping case and we need to combine it 
    {
        end=max(end,arr[j][1]);
    }
    else
{
    break; // if j does not have the overlapping case then j+1 will not have so we will break from the loop 
}


}
ans.push_back({start,end}); // pushing the final overlapped interval to the ans array 

}
return ans;
}


// more optimized solution 

vector<vector<int>> mergeOverlapping(vector<vector<int>> &arr) 
{

int n=arr.size();
sort(arr.begin(),arr.end());

vector<vector<int>>ans;

for(int i=0; i<n; i++)
{
    if(ans.empty() || arr[i][0]>ans.back()[1]) // it means the element is not overlapping since its inital value is greater than the final value of the interval 
    {
        ans.push_back(arr[i]);
    }

    else
    {
        ans.back()[1]=max(ans.back()[1],arr[i][1]); // if overlapping then  take directly instead 
    }
}

return ans;

}






int main()
{





    return 0;
}


/*

so we can solve this quesiton via twoo approach 


for(int i=0; i<n; i++)
{
    if(ans.empty() || arr[i][1]<ans.back()[1])

    {
        ans.push_back(arr[i]);
    }
    else
    {
        ans.back()[1]=max(ans.back()[1],arr[i][1]);
    }




}



*/