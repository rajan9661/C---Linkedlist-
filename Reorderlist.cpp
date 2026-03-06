
class Solution {
public:
   ListNode *reverse(ListNode *slow) {
    ListNode *prev=NULL;
    ListNode *curr=slow;
    ListNode *nextnode=curr;
      while(curr!=NULL) {
        nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
   }
   return prev;
   }
    void reorderList(ListNode* head) {
     // find middle of linked list;
     if(head==NULL) return;
    if(head->next==NULL) return;
     ListNode *slow=head;
     ListNode *fast=head;
     while(fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
     } 
      ListNode* rev=reverse(slow->next);
      slow->next=NULL;
      ListNode* temp=head;
      ListNode* dummy=new ListNode(-100);
      ListNode* rajan=dummy;
      while(temp!=NULL && rev!=NULL) {
        rajan->next=temp;
        temp=temp->next;
        rajan=rajan->next;
        rajan->next=rev;
        rev=rev->next;
        rajan=rajan->next;
      } 
      if(rev==NULL) {
        rajan->next=temp;
      }
      else rajan->next=rev;
      return ;
    }
};