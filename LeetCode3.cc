//
//  LeetCode3.cc
//  
//  Created by Heng-Yi Lin on 2/25/16.
//
//

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