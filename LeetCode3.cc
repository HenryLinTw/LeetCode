//
//  LeetCode3.cc
//  Created by Heng-Yi Lin on 2/25/16.
//  
//  title: 3. Longest Substring Without Repeating Characters
//  Given a string, find the length of the longest substring without repeating characters. For example, the longest 
//  substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b",
//  with the length of 1.
//
//  solution: 
//  *use array to present a fake hashtable, store index of each encountering char in with array index from its ascii (0-127 for all characters).   
//  loop through the string, 
//  1) if the char doesn't exist in the substring, increment length and store its index in fake hashtable 
//  2) if exists, 
//      a. check if the substring is greater than longest length
//      b. update start position to next index of the first repeating char and calculate tmp length from that position
//      c. update fake hashtable for that char

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, tmp = 0, startpos = 0;
        int flag[127];
        fill_n(flag, 127, -1);
        
        for (int i=0; i<s.length(); i++) {
            if (flag[s[i]]<startpos) { // the char doesn't show before
                tmp++;
                flag[s[i]] = i;
            } else { // the char exists
                longest = tmp > longest ? tmp : longest;
                startpos = flag[s[i]] + 1;
                tmp = i - startpos + 1;
                flag[s[i]] = i;
            }
        }
        
        return tmp > longest ? tmp : longest;
        
    }
};
