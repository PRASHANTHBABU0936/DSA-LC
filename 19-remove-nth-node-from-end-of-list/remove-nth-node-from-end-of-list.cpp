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
        ListNode* temp = head;
        int lent=0;
        while(temp != NULL){
            temp=temp->next;
            lent++;
        }
        int wngt=lent-n;
      ListNode* rtemp = head;
int h=1;
if(wngt==0){
    ListNode* first=head;
    head=head->next;
    delete(first);
    return head;
}
while(h!=wngt){
    rtemp=rtemp->next;
    h++;
}

// if (rtemp->next != NULL){


// }

if(rtemp->next != NULL && rtemp->next->next != NULL){ListNode* hell=rtemp->next;
rtemp->next=rtemp->next->next;
delete(hell);}
else {
    ListNode* hell=rtemp->next;
    rtemp->next=NULL;
    delete(hell);
}




    return head;}
};