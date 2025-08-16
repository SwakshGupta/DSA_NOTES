/*
Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABABC", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.




*/




#include <iostream>
#include <vector>
using namespace std;

int lonString(string s, int k)
{
    int l = 0;
    int r = 0;
    int n = s.size();
    int result = 0;
    int maxi = 0;

    vector<int> hashmap(26, 0); // using vector instead of unordered_map for efficiency

    while (r < n)
    {
        hashmap[s[r] - 'A']++; // character-A gives us the ASCII value of the character 

        maxi = max(maxi, hashmap[s[r] - 'A']); // here we are calculating the maximum frequency in the hashmap

        while ((r - l + 1) - maxi > k) // in case len-maxfrequency is > than k then this will happen
        {
            hashmap[s[l] - 'A']--; // decreasing the frequency of element which was trimmed when we are moving left pointer 
            l++;
            
        }

        result = max(result, r - l + 1); // update the result with the current window size
        r++;
    }

    return result;
}

int main()
{
    string s = "ABAB";
    int k = 2;
    cout << lonString(s, k) << endl; // Expected output: 4
    return 0;
}
