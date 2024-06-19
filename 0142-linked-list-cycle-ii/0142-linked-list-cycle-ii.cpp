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
    ListNode *detectCycle(ListNode *head) {
        ListNode *curr;
        ListNode *fast = head;
        ListNode *slow= head;
        
        while(fast!=NULL&& fast->next !=NULL&& slow){
        
           
            fast = fast->next->next;
            slow= slow->next;
            
            if(fast == slow) {
                //once fast reaches slow => we got into loop and then increment fast slow simultanealy at same speef and once again they meet => fast contains node that causes loop
                fast = head;
                while(fast!=slow){
                    fast = fast->next;
                    slow= slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};