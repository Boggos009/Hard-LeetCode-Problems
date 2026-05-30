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
