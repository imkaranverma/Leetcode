/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy-> next = head;
        
        ListNode *s = dummy;
        ListNode *f = dummy;

            if(head -> next == 0 && n==1)
                head = 0;


        for(int i=1 ; i<=n ; ++i){
            f= f->next;
            cout<< i<<endl;
        }

        while(f->next != NULL){
            f= f-> next;
            s= s-> next;
            // cout << "while"<< endl;
        }

        // cout<< s->next <<endl;
        // cout<< s -> next -> next <<endl;


        if(s->next != head){
        s-> next = s-> next->next;
        // cout<< "one"<<endl;
        }
        else 
        {
           ListNode *temp = head;
            head = temp-> next;
            // head->next = temp-> next ->next;
            // free(temp);
        // cout<< "two"<<endl;
        }
        return head;
    }
};