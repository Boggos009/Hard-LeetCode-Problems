#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<int , TrieNode*> mp;
    bool isLeaf;
    TrieNode(){
        mp.clear();
        isLeaf = false;
    }
};

class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        this->root = new TrieNode();
    }
    void Insert(string s)
    {
        TrieNode* cur = root;
        for(char& c: s){
            if(cur->mp.count(c)==false){
                cur->mp[c] = new TrieNode();
            }
            cur = cur->mp[c];
        }
        cur->isLeaf = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie dict = Trie();
        for(string& word: dictionary){
            dict.Insert(word);
        }
        int n = s.size();
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--){
            dp[i] = 1+dp[i+1];
            TrieNode* cur = dict.root;
            for(int j= i;j<n;j++){
                if(cur->mp.count(s[j])==false) break;
                cur = cur->mp[s[j]];
                if(cur->isLeaf)dp[i] = min(dp[i], dp[j+1]);
            }
        }
        return dp[0];
    }
};