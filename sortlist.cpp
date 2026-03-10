
class Solution {
public:
   ListNode* mergesort(ListNode *l1,ListNode *l2) {
    ListNode* dummy=new ListNode(-214748364);
    ListNode *temp=dummy;
    while(l1!=NULL && l2!=NULL) {
        if(l1->val<=l2->val) {
            temp->next=l1;
            l1=l1->next;
        }
        else{
           temp->next=l2;
           l2=l2->next;
        } 
        temp=temp->next;
    }
    if(l1==NULL) temp->next=l2;
    else temp->next=l1;
    return dummy->next;
   }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* left=head;
        ListNode* right=slow->next;
        slow->next=NULL;
         left=sortList(left);
       right=sortList(right);

        return mergesort(left,right);
    }
};