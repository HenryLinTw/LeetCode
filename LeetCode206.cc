//
//  LeetCode206.cc
//  Created by Heng-Yi Lin on 3/3/16.
//
//  title: 206. Reverse Linked List
//  Reverse a singly linked list.
//
//  Hint:
//  A linked list can be reversed either iteratively or recursively. Could you implement both?
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /** Iteration **/
         ListNode *prev = nullptr;
         ListNode *current = head;
         ListNode *next = nullptr;
        
         while (current) {
             next = current->next;
             current->next = prev;
             prev = current;
             current = next;
         }
         return prev;
        
        /** Recursion **/
        if (!head) return nullptr;
        if (!head->next) return head;
        
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    
};