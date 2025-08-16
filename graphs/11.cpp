/*problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.

Note: Many orders may be possible for a particular test case, thus you may return any valid order.

Examples:

Example 1:
Input: N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output: b d a c
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

string findOrder(string dict[], int n, int k)
{
    vector<int> adj[k]; // k was the number of alphabet in the string 

    // here we will create the graph by comparing elemets one by one 

    for(int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int len = min(s1.length(), s2.length());
        for(int j = 0; j < len; j++ )
        {
            if(s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a'); // why -a cuz we want to store number in the adjoint 

                break; // break the loop if you find any different element and make its mapping 
            }
        }
    }

    // from the previous code we have figure out the graph or the adjacent elements now we will do the topo sort of the elements

    vector<int> indegree(k, 0);

    // calculate indegree
    for(int u = 0; u < k; u++)
    {
        for(auto v : adj[u])
        {
            indegree[v]++;
        }
    }

    queue<int> q;

    // push all elements with indegree 0
    for(int i = 0; i < k; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    string ans = "";

    // Kahn's algorithm
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        ans += (char)(u + 'a');

        for(auto v : adj[u])
        {
            indegree[v]--;

            if(indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return ans;
}

int main()
{
    int N = 5, K = 4;
    string dict[] = {"baa","abcd","abca","cab","cad"};

    string order = findOrder(dict, N, K);

    cout << "Order of characters: " << order << endl;

    return 0;
}

// if you dont get it watch striver video for that 