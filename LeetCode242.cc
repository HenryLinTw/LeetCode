//
//  LeetCode242.cc
//  Created by Heng-Yi Lin on 2/28/16.
//
//  242. Valid Anagram
//  Given two strings s and t, write a function to determine if t is an anagram of s.
//
//  For example,
//  s = "anagram", t = "nagaram", return true.
//  s = "rat", t = "car", return false.
//
//  Note:
//  You may assume the string contains only lowercase alphabets.
//
//  Follow up:
//  What if the inputs contain unicode characters? How would you adapt your solution to such case?//
//
//  Analysis:
//      1) Length must be the same
//      2) the number of presence for each char must be the same
//
//  Solution:
//  Use ascii code as index presenting fake hash table and store number of presence for each char
//  -> First, fill chars and increment their counts in fake hash table.
//     Then, use the other string to decrement count (or delete item) in fake hash table
//     Last, check if the fake hash table back to non filled state
//
//      Sol 1) map (key: ascii; value: count)
//      Sol 2) array (index: ascii; value: count)
//      *Sol 1 is much more slower than Sol 2. Use map is unnecessary and runtime increases
//      tremendously due to logarithmic complexity of find(), insert(), and erase()
//
class Solution {
public:
    bool isAnagram(string s, string t) {
        // check corner cases
        if (s.empty() && t.empty()) return true;
        else if (s.empty() || t.empty()) return false;
        if (s.length() != t.length()) return false;
        

        /****************************Solution 1: map*****************************************/

        // first int as ascii code of each char; second int as count for each code
        map<int,int> hashmap;
        
        // fill in hashamp with string s
        for (int i=0; i<s.length(); i++) {
            if (hashmap.find(s[i]) != hashmap.end()) // exists
                hashmap[s[i]]++;
            else
                hashmap.insert(pair<int,int>(s[i],1));
        }
        
        // delete count in hashmap until exhausted (delete item if it's last one)
        // retur false if no match key
        for (int i=0; i<t.length(); i++) {
            if (hashmap.find(t[i]) == hashmap.end()) // not exists
                return false;
            else {
                if (hashmap[t[i]] == 1)
                    hashmap.erase(t[i]);
                else
                    hashmap[t[i]]--;
            }
        }
        
        // if still any item in the map, means its not
        return hashmap.size() == 0 ? true : false;
        
    
        /****************************Solution 2: array*****************************************/
        /*****************************ENHANCE RUNTIME******************************************/
    
        int fakeHash[256];
        std::fill(fakeHash, fakeHash+256, 0);
        
        for (int i=0; i<s.length(); i++)
            fakeHash[s[i]]++;
        for (int i=0; i<t.length(); i++)
            fakeHash[t[i]]--;
        for (int i=0; i<256; i++)
            if (fakeHash[i]!=0) return false;
        return true;
        
    }
};