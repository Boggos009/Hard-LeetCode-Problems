# Intuition  
1- u need to solve 895. Maximum Frequency Stack and if u want any help u can read geek for geeks article:  
https://www.geeksforgeeks.org/dsa/design-a-stack-which-can-give-maximum-frequency-element/

2- solve 146. LRU Cache and if u want any help u can watch this video from neetcode  
https://www.youtube.com/watch?v=7ABFKPK2hD4&source_ve_path=OTY3MTQ&embeds_referring_euri=https%3A%2F%2Fneetcode.io%2F

3- from 1 and 2 u can easy combine these two problems' solutions to build LFU Cache

---

# Approach  
- use doubly linked list to implement LRUCache inside each frequency bucket so we can remove and insert in O(1)  
- maintain a hashmap that maps key -> node  
- maintain a hashmap that maps key -> frequency  
- maintain a hashmap that maps frequency -> DLL (LRU structure)  
- keep track of minCount which is the minimum frequency currently in the cache  
- when a node is used, remove it from its current frequency list and move it to freq + 1 list  
- if a frequency list becomes empty and it was the minCount, increase minCount  

---

# Complexity  
- Time complexity:  
O(1) for both get and put  

- Space complexity:  
O(n) where n is the number of elements stored in the cache  

---

# Code  
```cpp
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
            node->val = value;

            cashemp[freqmp[key]].removeNode(node);

            if(cashemp[minCount].LRU == nullptr) minCount++;

            freqmp[key]++;

            cashemp[freqmp[key]].insertToMRU(node);
        }
        else{
            if(mp.size() == cap){
                Node* deleted = cashemp[minCount].LRU;

                freqmp.erase(deleted->key);
                cashemp[minCount].removeNode(deleted);
                mp.erase(deleted->key);
            }

            Node* t = new Node(key, value);

            mp[key] = t;
            freqmp[key] = 1;

            cashemp[1].insertToMRU(t);
            minCount = 1;
        }
    }
};