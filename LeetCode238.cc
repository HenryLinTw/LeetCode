//
//  LeetCode238.cc
//  Created by Heng-Yi Lin on 2/28/16.
//
//  title: 238. Product of Array Except Self
//  Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal
//  to the product of all the elements of nums except nums[i].
//
//  Solve it without division and in O(n).
//  For example, given [1,2,3,4], return [24,12,8,6].
//
//  Follow up:
//  Could you solve it with constant space complexity? (Note: The output array does not count as extra
//  space for the purpose of space complexity analysis.)
//
//  Solution:
//  Loop to right end, multiply all number before and put into result
//  Loop to left end, mulitply all number after into result
//  *corner case:
//      first item (loop to right end): directly put into result
//      last item (loop to left end): do nothing

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numSize = nums.size();
        if (nums.size() <= 1) return nums;
        
        int product = 1;
        vector<int> result;
        
        // loop to the right end
        result.push_back(product); // first one
        for (int i=1; i<numSize; i++) {
            product *= nums[i-1];
            result.push_back(product);
        }
        
        // loop to the left end
        product = 1;
        for (int i=numSize-2; i>=0; i--) { // start from the last but one
            product *= nums[i+1];
            result[i] *= product;
        }
        return result;
    }
};
