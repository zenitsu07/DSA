
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* isPalindrome(ListNode* head) {
        
        ListNode* prev;
        ListNode* curr;
        ListNode* then;
        //3 pointer approach
        prev= nullptr;
        curr = head;
        then = head;//next pointer
        
        while(curr!=nullptr){
            then = head->next;
            curr->next = prev;
            prev = curr;
            curr = then;
        }

        return prev;

        // while(prev!=nullptr&&head!=nullptr){
        //     // if(prev->val != head->val){
        //     //    return false;
        //     // }
        //     prev = prev->next;
        //     head = head->next;
        // }
        // return true;
    }
};