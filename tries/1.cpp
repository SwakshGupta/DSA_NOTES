/*
Tries is a tree like data strcutre which is use to store string for searching and inserting purpose 


so in this whole code i have defined the ties class with some functions


1. Then i have created three seperate functions for insetion,prefixes and searching 


*/

#include<iostream>
using namespace std;

struct Node {

    Node* links[26]; // here we have created a link of array of size 26

    bool flag = false; // this is the structure for our tries 

    bool containKey(char ch) {
        return links[ch - 'a'] != NULL; // checks in the character path exist 
    }

    void put(char ch, Node* node)   // here we are creating a path for a character 
    {
        links[ch - 'a'] = node; // so this new ch is pointing to the  new reference node
    }

    Node* get(char ch) {
        return links[ch - 'a']; // move to the child node corresponding to the character 
    }

    void setEnd() {
        flag = true;  // marks the end of the word 
    }

    bool isEnd() {   // here it marks the end of the word 
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // here we have written the insert function for the ties 

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) // checks if the path exist  
            {
                node->put(word[i], new Node()); // if it did not exist then create one path 
            }

            // if the node contains the word then we will just move to  the refernce trie
            node = node->get(word[i]); // move to the reference trie 
        }
        node->setEnd(); // mark end of word
    }

    // here we have written the seaarch function for the ties data structure 
    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) {
                return false; // means if the path does not exist then return false 
            }

            node = node->get(word[i]); // otherwise move forward 
        }

        return node->isEnd(); // at the end return isEnd function which will return us the flag 
    }

    // now we will write the prefix function 
    bool prefixs(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containKey(prefix[i])) {
                return false; // that is if the path does not exist then return false 
            }

            node = node->get(prefix[i]); // otherwise keep moving forward
        }

        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    // Example test cases
    cout << trie.search("apple") << endl;   // Output: 1 (true)
    cout << trie.search("app") << endl;     // Output: 1 (true)
    cout << trie.search("appl") << endl;    // Output: 0 (false)
    cout << trie.prefixs("appl") << endl;   // Output: 1 (true)
    cout << trie.prefixs("bat") << endl;    // Output: 0 (false)

    return 0;
}


