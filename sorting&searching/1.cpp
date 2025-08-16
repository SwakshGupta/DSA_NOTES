/*

Merge sorting all the previous sorting techniques were taking o(n^2) to solve but this takes O(nlogn)




*/

#include<iostream>
using namespace std;



void merge(vector<int>&arr,int low,int mid,int high)
{
vector<int>temp; // we are creating a temp  variable here

int left=low;
int right=mid+1;

while(left<=mid && right<=high)
{

if(arr[left]<=arr[right])
{
    temp.push_back(arr[left++]);
}

if(arr[left]>=arr[right])
{
    temp.push_back(arr[right++]);
}
}

// if left elements are left to be combined

while(left<=mid)
{
    temp.push_back(arr[left++]);
}

while(right<=high)
{
    temp.push_back(arr[right++]);
}

// now putting everything in the array 

for(int i=0; i<high; i++)
{
    arr[i]=temp[i-low];
}



}








void mergeSort(vector<int>&arr,int low,int high)
{
 int mid=(low+high)/2;

 if(high<=low)
 {
    return;
 }

mergeSort(arr,low,mid);
mergeSort(arr,mid+1,high);  // so here we are divinding the array into two parts and then we are going to merge them 

merge(arr,low,mid,high); // in this code we will merge the arrays in the sorted order and hence 


}





int main()
{




    return 0;
}


/*

int findLongest(vector<int>&nums)
{
    unordered_map<int,int>maps;
    int len=0;
    int maxLen=0;
    int sum=0;


    if(int i=0; i<nums.size(); i++)
    {
        sum+=nums[i];

        if(sum==0)
        {
            len=i+1;
            maxLen=max(maxLen,len)
        }

        int rem=sum;

        if(maps.find(rem)!-maps.end())
        {
            len=i-maps[rem];
            maxLen=max(maxLen,len);
        }

maps[sum]=i;


    }

}









*/