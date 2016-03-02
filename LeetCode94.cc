//
//  LeetCode94.cc
//  Created by Heng-Yi Lin on 3/1/16.
//
//  title: 94. Binary Tree Inorder Traversal
//  Given a binary tree, return the inorder traversal of its nodes' values.
//
//  For example:
//  Given binary tree {1,#,2,3},
//  1
//   \
//    2
//   /
//  3
//  return [1,3,3].
//
//  Note: Recursive solution is trivial, could you do it iteratively?//
//
//  *Tree Traversal can be divided into Depth-first search and Breadth-first search
//  Depth-first search can be further classified as:
//  ．Pre-order
//      1.Display the data part of the root (or current node).
//      2.Traverse the left subtree by recursively calling the pre-order function.
//      3.Traverse the right subtree by recursively calling the pre-order function.
//  ．In-order
//      1.Traverse the left subtree by recursively calling the pre-order function.
//      2.Display the data part of the root (or current node).
//      3.Traverse the right subtree by recursively calling the pre-order function.
//  ．Post-order
//      1.Traverse the left subtree by recursively calling the pre-order function.
//      2.Traverse the right subtree by recursively calling the pre-order function.
//      3.Display the data part of the root (or current node).
//
//  ref: https://en.wikipedia.org/wiki/Tree_traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        /** Method 1: recursion **/
//         vector<int> result;
//         if (root != nullptr) {
//
//             vector<int> left = inorderTraversal(root->left);
//             result.insert(result.end(), left.begin(), left.end());
//
//             result.push_back(root->val);
//        
//             vector<int> right = inorderTraversal(root->right);
//             result.insert(result.end(), right.begin(), right.end());
//        
//         }

        /** Method 2: iteration (stack) **/
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> treeStack;
        TreeNode *node = root;
        
        while (!treeStack.empty() || node)
        {
            if (node)
            {
                treeStack.push(node);
                node = node->left;
            }
            else
            {
                node = treeStack.top();
                treeStack.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        
        return result;
    }
};