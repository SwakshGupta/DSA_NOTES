/*
Allocate books 

here we are given with an array of number of pages in a book we have to allocate  book in such a way that the maximum
no of pages allocated to the student in minimum

1. there are m student and we have allocate everystudent a book
2. book should be allocated in a contigoous manner 
3. one book could be allocated to one student only 






*/

#include<iostream>
using namespace std;

int stuCount(vector<int>nums,int pages)
{
int stu=1; // this is the student counter 

int pageStudent=0; // this shows number of pages student have initial student have zero pages so the value 0

for(int i=0; i<nums.size()-1; i++ )
{
if(pageStudent+nums[i]<=pages) // if sum<(pages(which is maximum pages student can hold )) then we will increase the pages 
{
    pageStudent+=nums[i];
}
else
{
    stu++; // we will increase the student 

    pageStudent=nums[i];
}
}

return stu; // will later check value of stu through which we will change the range of low and high 
}








int findPages(vector<int>arr,int n,int m) // n is the size of array and  m is the number of students 
{
    int ans=0;

if(m>n)
return -1; // if the number of studets are greater than the book then we can't allocate book to every student

int low=*max_element(arr.begin(),arr.end());
int high=0;

// high is sum of all the elements 
for(int i=0; i<n;i++)
{
    high+=arr[i];
}

while(low<=high)
{
    int mid=low+(high-low)/2; // mid give us max number of pages a student can hold and we have to minimize that thing 

    int student=stuCount(arr,mid);

    if(student==m) // we will check whether the stunent return==m is yes then that could be the possible answer 
    {
        ans=min(ans,mid);
    }

    else if(student>m)
    {
        low=mid+1; // if more than m students are accmulating the books that means we have to increase mid (which gives max number of pages a studnet can hold)
    }
    else if(student<m)
    {
        high=mid-1;
    }
}

return ans;
}




int main()
{




    return 0;
}