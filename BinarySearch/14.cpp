/* important adn hard question

Finding median of two sorted arrays

*/




#include<iostream>
using namespace std;

double median(vector<int>&a,vector<int>&b)
{
    int n1=a.size();
    int n2=b.size();

    if(n1>n1) return median(b,a); // we always want n1 to be smaller that is why we are calling median(b,a)

// now BS search reqpresnts the number of elements selected 
int low=0;
int high=n1;

int left=(n1+n2+1)/2; // if the number of elements are uneual these would be number of elements present in the left half

int n=n1+n2;

while(low<=high)
{
    int mid1=(low+high)>>1;
    int mid2=left-mid1;

    // now we will assign random values to left half and the right half
    int l1=INT_MIN;
    int l2=INT_MIN;
    int r1=INT_MAX;
    int r2=INT_MAX;

    if(mid1<n1)
    r1=a[mid1];

    if(mid2<n2)
    r2=b[mid2];

    if(mid1-1>=0)
    l1=a[mid1-1];

    if(mid2-1>=0)
    l2=b[mid2-1];

//now we will change the low and high value according to these above values

if(l1<=r2 && l2<=r1)
{
    if(n%2==1) // odd number 
    {
        return max(l1,l2);
    }

    else // even number
    {
        return (double)(max(l1,l2)+min(r1,2)/2);
    }
}
else if(l1>r2) high=mid1-1;
else low=mid1+1;

}

}







int main()
{





    return 0;
}