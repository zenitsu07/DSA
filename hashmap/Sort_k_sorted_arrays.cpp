
 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


class Solution {
public:
    
     ListNode* mergeLists(ListNode* l1, ListNode* l2) {
            if(l1 == NULL){
                return l2;
            }
            if(l2 == NULL){
                return l1;
            }        
            if(l1->val < l2->val){
                l1->next = mergeLists(l1->next, l2);
                return l1;
            }
            else{
                l2->next = mergeLists(l1, l2->next);
                return l2;            
            }
        }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int,vector<int>,greater<int> >pq;
        if(lists.size()==0 ) return NULL;
        
        // for(int i =0; i <lists.size() ;i++){
            
        //     //here lists[i] resperesent ith list to access its head 
        //     ListNode* head = lists[i];
        //     while(head!=NULL){

        //         pq.push(lists[i]->val);
        //         head = head->next;
        //     }
        // }
     
        // ListNode* start = NULL;
        // ListNode* curr = NULL;
        
        // while(!pq.empty()){
            
        //     if(start == NULL){
        //         start = new ListNode(pq.top());
        //         curr = start;
        //         pq.pop();
        //     }
        //     else{
        //         curr->next = new ListNode(pq.top());
        //         curr = curr->next;
        //         pq.pop();
        //     }
            
        // }
        
        // return start;
       
        ListNode* head = NULL;
        int n = lists.size();
        if(n==0) return head;
        
        int  i = 0;
        
        for(int i = 1; i<n;i++) {

           lists[i] = mergeLists(lists[i-1],lists[i]);
        
        }
        return lists[n-1];
        
    }
};
