/*
Merge two sorted arrays without any space 


*/



#include<iostream>
using namespace std;



// optimal solution 1

void merge(long long arr1[],long long arr2[],int n,int m)
{

int left=n-1;
int right=0;

while(left>=0 && right <m)
{

if(arr1[left]>arr2[right])
{
    swap(arr1[left],arr2[right]);
    left--,right++;
}

else
{
    break; // if this condition is not true then break out of the loop 
}
}

sort(arr1,arr1+n); // in the end we are sorting both the arrays 
sort(arr2,arr2+m);
}


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        // last valid element in nums1
        int j = n - 1;        // last element in nums2
        int k = m + n - 1;    // last index in nums1 (total space)

        // Merge from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining nums2 elements (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }



int main()
{



    return 0;
}

/*

void merge(long long arr1[],long long arr2[],int n,int m)
{

int right=0;
int left=n-1;

while(left>=0 && right<m)
{

if(arr[left]>arr2[right])
{
    swap(arr[left],arr2[right]);
    left--;
    right++;
}

else
{
    break;
}
}

sort(arr1.begin(),arr2.end());
sort(arr2.begin(),arr2.end())






}





*/