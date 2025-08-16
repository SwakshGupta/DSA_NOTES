/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/



#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string solve(string str,int k)
{
    stack<char>st;
    int n=str.size();

    for(int i=0; i<n; i++)
    {
        while(!st.empty() && k>0 &&(st.top()-'0')>(str[i]-'0')) 
        // str-'0'covert the digit into integer value 
        // if string top is greater then we will pop the element and decrement the value of k 
        {
            st.pop();
            k--;
        }
        st.push(str[i]); 
    }

    while(k>0)
    {
        st.pop();
        k--;  // while traversing through all the elements if our k is still not zero then we pop out first k elements from our stack 
    }

    if(st.empty())
    {
        return "0";
    }

    string res="";
    while(!st.empty())
    {
        res=res+st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());  // reversing the string to correct the order

    // now we will remove leading zeros 
    int i = 0;
    while (i < res.size() && res[i] == '0') {
        i++;
    }

    res = res.substr(i);  // remove leading zeros

    if(res.empty()) return "0";
    
    return res;
}


int main()
{
    string num = "1432219";
    int k = 3;
    cout << "Result: " << solve(num, k) << endl;

    return 0;
}
