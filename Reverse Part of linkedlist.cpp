
class Solution {
public:
// Ist Code published;
    ListNode *reverse(ListNode *head,int left,int right) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        for(int i=1;i<=left-1;i++) {
            curr=curr->next;
        }
        ListNode *nextNode=curr;
        int i=left;
        while(i<=right) {
           nextNode=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nextNode;
           i++;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;
        int i=1;
        ListNode *tempa;
        ListNode *tempb;
        tempa=head;
        tempb=head;
          for(i=1;i<=left-2;i++) {
            tempa=tempa->next;
          }
          for(int i=1;i<=right;i++) {
            tempb=tempb->next;
          }
          ListNode *rajan=reverse(head,left,right);
          ListNode *leftNode=head;
          for(int i=1;i<left;i++) {
            leftNode=leftNode->next;
          }
           if(left!=1) tempa->next=rajan;
          else head=rajan;
           leftNode->next=tempb;
          return head;
    }
};
