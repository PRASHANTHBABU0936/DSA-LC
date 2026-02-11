class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL) return NULL;

        int len = 0;
        ListNode* t = head;
        while(t != NULL){
            len++;
            t = t->next;
        }

        int h = len - n;  
        if(h == 0){
            ListNode* del = head;
            head = head->next;
            delete(del);
            return head;
        }

        int i = 1;
        ListNode* temp = head;        while(i < h){
            temp = temp->next;
            i++;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete(del);

        return head;
    }
};
