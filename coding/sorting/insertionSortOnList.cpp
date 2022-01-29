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
    ListNode* insertionSortList(ListNode* head) {
        
        if(!head)
            return head;
        
        
        ListNode* prev1 = head;
        ListNode* temp = head->next;
        ListNode* start = NULL;
        ListNode* prev = NULL;
        ListNode* store = NULL;
        
        while(temp){
            
            
            start = head;
            prev = NULL;
            
            if(prev1->val <= temp->val){
                prev1 = temp;
                temp = temp->next;
                continue;                
            }
            
            while(start->val < temp->val){
                prev = start;
                start = start->next;
                
            }
            
            

            
            prev1->next = temp->next;
            
            
            
            
            if(prev == NULL){
                
                temp->next = head;
                head = temp;
                
                
                
            }
            else{
                
                store = prev->next;
                prev->next = temp;
                temp->next = store;
                
                
            }
            
            temp = prev1->next;
            
        }
     return head;   
    }
};
