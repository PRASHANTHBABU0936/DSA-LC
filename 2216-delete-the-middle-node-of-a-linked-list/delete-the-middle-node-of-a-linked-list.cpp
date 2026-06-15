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
    ListNode* deleteMiddle(ListNode* head) {
            ListNode* slow=head;
            ListNode* fast=head;
             ListNode* temp=head;
              ListNode* orig=head;
if(head == NULL) return NULL;
if(head->next == NULL) return NULL;
if(head->next->next == NULL) {
    head->next = NULL;
    return head;
}
      while(fast != NULL && fast->next != NULL ){
slow=slow->next;
fast=fast->next->next;
      }  
// if(slow == head) return NULL; //


while(temp->next != slow){

temp=temp->next;
}
ListNode* deel=temp->next;
temp->next=deel->next;
delete(deel);


    return orig;}
};