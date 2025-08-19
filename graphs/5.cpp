/*
Word Ladder Problem


A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.


approach

1 . create a set vector where insert everyword in the set 

2. create a queue of string and count traverse the queue replace each element  and check whether that element exist in the set or not 

3. If that word exist then just push that word into the queue and increase the counter 


*/




#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

int wordLadderLength(string startWord,string TargetWord,vector<string>&wordList)
{
queue<pair<string,int>>q;
q.push({startWord,1});    // when we push something into the queue we mark that as visited 

unordered_set<string>st(wordList.begin(),wordList.end());
st.erase(startWord); // since we have pushed that word into the queue so we will erase it 

// now we will do BFS

while(!q.empty())
{
    string word=q.front().first;
    int count=q.front().second;
    q.pop();

    if(word==TargetWord) return count; // means if we reach to the target word then return the count 

    // now we will traverse across all the words

    for(int i=0; i<word.size(); i++)
    {
      char original=word[i];

      // now we will replace this original character with everypossible alphabet and then we will check is there any match from the set

      for(char ch='a'; ch<'z'; ch++)
      {
        word[i]=ch;
        if(st.find(word)!=st.end()) // it means that word is present so we will pop that word from the set and push that word into the queue 
        {
            st.erase(word);
            q.push({word,count+1});

        }
      }
      word[i]=original; // so that it word gets its original charcter back once check is done cuz we can check only one word at a time 


    }
}

return 0; // if targetword is not found then return 0

}





int main()
{





    return 0;
}