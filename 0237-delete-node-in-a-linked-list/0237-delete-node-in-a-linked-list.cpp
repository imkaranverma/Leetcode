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
    void deleteNode(ListNode* node) {
        

        // ListNode* temp= node;

        // while(temp->next->next){
        //         temp->val = temp->next->val;  
        //         temp = temp->next;
        // }

        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};