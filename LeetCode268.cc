//
//  LeetCode268.cc
//  Created by Heng-Yi Lin on 3/1/16.
//
//  title: 268. Missing Number
//  Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is
//  missing from the array.
//
//  For example,
//  Given nums = [0, 1, 3] return 2.
//
//  Note:
//  Your algorithm should run in linear runtime complexity. Could you implement it using only constant
//  extra space complexity?
//
//  Solution:
//  Sum up all numbers in the vector and substract the total(n*(n+1)/2) by sum.
//

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        
        return nums.size()*(nums.size()+1)/2 - sum;
    }
    
};