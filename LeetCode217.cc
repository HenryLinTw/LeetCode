//
//  LeetCode217.cc
//  Created by Heng-Yi Lin on 3/1/16.
//
//  title: 217. Contains Duplicate
//  Given an array of integers, find if the array contains any duplicates. Your function
//  should return true if any value appears at least twice in the array, and it should
//  return false if every element is distinct
//
//  Solution:
//      sol 1) [around 100 ms] While using map or set, the time complexity is approaching
//              but greater and not exactly O(N). since it would be affect by the number
//              of data in the map or set
//      sol 2) [around 36 ms] way more fast. sorting vector takes O(NlogN) and checking
//              with loop also takes O(N). therefore the time complexity is O(NlogN).
//

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /** sol 1 - map **/
         map<int,bool> hashmap;
         for (int i=0; i<nums.size(); i++) {
             if (hashmap.find(nums[i])!=hashmap.end())
                 return true;
             else
                 hashmap.insert(pair<int,bool>(nums[i],true));
         }
        
        /** sol 1 - set **/
         set<int> checker;
         for (int i=0; i<nums.size(); i++) {
             if (checker.find(nums[i])!=checker.end())
                 return true;
             else
                 checker.insert(nums[i]);
         }
        
        
        /** sol 2 **/
        sort(nums.begin(), nums.end());
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]==nums[i-1])
                return true;
        }
        
        return false;
    }
};