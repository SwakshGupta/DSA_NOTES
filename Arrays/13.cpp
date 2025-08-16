
/*  count inversions problems where arr[i]>arr[j] where i<j we  have to find such pairs

so we will be using merge sort here so that we can get two sorted arrays from there we will calculate all the sorted arrays 


approach is written in the notebook 




*/




#include<iostream>
using namespace std;

// we are doing little bit changes in the  merge sort array 



int merge(vector<int>&arr,int low,int mid,int high)
{
vector<int>temp; 

int left=low;
int right=mid+1;

int count=0;
while(left<=mid && right<=high)
{

if(arr[left]<=arr[right])
{
    temp.push_back(arr[left++]);
}

if(arr[left]>=arr[right])  // this was the case of inversion 
{
    temp.push_back(arr[right++]);

    count+=(mid-left+1); // if one element is making pair then all the pair right to it will  make pair hence (mid-left+1)
}


}
while(left<=mid)
{
    temp.push_back(arr[left++]);
}

while(right<=high)
{
    temp.push_back(arr[right++]);
}


for(int i=0; i<high; i++)
{
    arr[i]=temp[i-low];
}

return count; // here we are returning the count 
}

int  mergeSort(vector<int>&arr,int low,int high)
{
    int cnt=0;
 int mid=(low+high)/2;

 if(high<=low)
 {
    return;
 }

cnt+= mergeSort(arr,low,mid); // so this is count which we will get after sorted array combine 
cnt+=mergeSort(arr,mid+1,high); 

cnt+=merge(arr,low,mid,high); 

return cnt;

}








int main()
{




    return 0;
}