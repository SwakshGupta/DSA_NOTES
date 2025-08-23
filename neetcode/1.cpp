// group anagram problem 

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            // Count frequency of each character
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Convert freq vector into a unique string key
            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#"; 
                // "#" to separate numbers (avoids ambiguity like "11" vs "1,1")
            }

            // Group anagrams by this key
            mp[key].push_back(s);
        }

        // Collect result
        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};


approach

1. we made a hashmap of string and vector frequency 

2. now for every string we will generate a unique pattern based on their frequecy and then we will make all the
the string of similar pattern into the vector 

3. then we will push every vector key pair into the ans 



*/