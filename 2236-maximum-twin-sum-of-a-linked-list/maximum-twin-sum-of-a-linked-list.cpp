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
    int pairSum(ListNode* head) {
        ListNode* hell=head;
        ListNode* prev=NULL;
        int n = 0;
        // ListNode* nexter=hell->next;
        while(hell != NULL){

    ListNode* nexter = new ListNode(hell->val);
     nexter->next = prev;
            prev = nexter;
            hell = hell->next;
            n++;
        }
        int maxi = 0;

        while(n-- > 0 && head != NULL && prev != NULL){
            if(n < 0) break; // safety (optional)

            int sum = head->val + prev->val;
            maxi = max(maxi, sum);

            head = head->next;
            prev = prev->next;

            if(n == 0) break;
        }

        return maxi;}
};