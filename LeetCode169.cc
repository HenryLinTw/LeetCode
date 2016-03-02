//
//  LeetCode169.cc
//  Created by Heng-Yi Lin on 3/1/16.
//
//  title: 169. Majority Element
//  Given an array of size n, find the majority element. The majority element is the
//  element that appears more than ⌊ n/2 ⌋ times.
//  You may assume that the array is non-empty and the majority element always exist in
//  the array.
//
//  Solution:
//     sol 1) [O(NlogN)] sorting and find and number whose counter is greater than size/2
//     sol 2) [time:O(N);Space:O(N)] count and fill into hash table; then iterator
//              through find counter > size/2
//     sol 3) [O(N)] Bit manipulation: 32 iterations, each calculating the number of 1's
//              for the ith bit of all n numbers. Since a majority must exist, therefore,
//              either count of 1's > count of 0's or vice versa (but can never be
//              equal). The majority number’s ith bit must be the one bit that has the
//              greater count.
//     sol 4) [O(N)] Moore voting algorithm: We maintain a current candidate and a
//              counter initialized to 0. As we iterate the array, we look at the current
//              element x:
//                  1.If the counter is 0, we set the current candidate to x and the
//                      counter to 1.
//                  2.If the counter is not 0, we increment or decrement the counter
//                      based on whether x is the current candidate.


class Solution {
public:
    int majorityElement(vector<int>& nums) {

        /** sol 1 - sorting and counting **/
        if(nums.size()==1) return nums[0];
        
         int counter = 1;
         int size = nums.size();
        
         sort(nums.begin(), nums.end());
         for (int i=1; i<size; i++) {
             if (nums[i] == nums[i-1]) {
                 counter++;
                 if (counter>size/2) return nums[i];
             }
             else
                 counter = 1;
         }
        
        /** sol 2 - hash table **/
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        for (unordered_map<int, int>::iterator itr = umap.begin(); itr != umap.end(); itr++)
        {
            if (itr -> second > nums.size()/2)
                return itr -> first;
        }
        
        /** sol 3 - bits manipulating **/
        int bitCnt[32];
        memset(bitCnt, 0, sizeof(bitCnt));
    
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if (nums[i] & (1 << j))
                    bitCnt[j]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bitCnt[i] > nums.size()/2)
                ans += (int)pow(2, i);
        }
        return ans;
        
        /** sol 4 - Moore voting Algorithm **/
        int nTimes = 0;
        int candidate = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            if(nTimes == 0)
            {
                candidate = nums[i];
                nTimes = 1;
            }
            else
            {
                if(candidate == nums[i])
                    nTimes ++;
                else
                    nTimes --;
            }
        }
        return candidate;
        
        
    }};