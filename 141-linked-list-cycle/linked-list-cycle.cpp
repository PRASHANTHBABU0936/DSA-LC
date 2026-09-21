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
unordered_set <ListNode*> st;
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == NULL) return false;

ListNode* temp = head;
while(temp->next != NULL){
    if(st.find(temp) != st.end()) return true;
st.insert(temp);
temp=temp->next;
}
    return false;}
};