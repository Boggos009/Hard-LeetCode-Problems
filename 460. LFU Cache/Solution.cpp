#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    int key;
    Node* prev, *next;
    Node(int k , int v){
        this->key = k;
        this->val = v;
        prev=next = nullptr;
    }
};

class LRUCashe
{
public:
    Node* LRU , * MRU;
    LRUCashe(){
        LRU= MRU= nullptr;
    }
    void removeNode(Node *node){
        if(node->prev) node->prev->next = node->next;
        else LRU = node->next;

        if(node->next) node->next->prev = node->prev;
        else MRU = node->prev;
    }

    void insertToMRU(Node *node){
        node->next = NULL;
        node->prev = MRU;

        if(MRU) MRU->next = node;
        MRU = node;

        if(LRU == NULL) LRU = node;
    }
};

class LFUCache {
private:
    int cap;
    unordered_map<int , Node*> mp;
    unordered_map<int  , LRUCashe> cashemp;
    unordered_map<int  , int> freqmp;
    int minCount=1;
public:
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)==false) return -1;
        Node* node = mp[key];
        cashemp[freqmp[key]].removeNode(node);
        freqmp[key]++;
        cashemp[freqmp[key]].insertToMRU(node);
        if(cashemp[minCount].LRU == nullptr) minCount++;
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->val= value;
            cashemp[freqmp[key]].removeNode(node);
            if(cashemp[minCount].LRU == nullptr) minCount++;
            freqmp[key]++;
            cashemp[freqmp[key]].insertToMRU(node);
        }
        else{
            if(mp.size()==cap){
                Node* deleted = cashemp[minCount].LRU;
                freqmp.erase(deleted->key);
                cashemp[minCount].removeNode(deleted);
                mp.erase(deleted->key);
            }
            Node* t = new Node(key, value);
            mp[key] = t;
            freqmp[key]++;
            cashemp[1].insertToMRU(t);
            minCount = 1;
        }
    }
};
