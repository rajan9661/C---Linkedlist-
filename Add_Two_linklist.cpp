
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *dummyNode=new ListNode(-1);
        ListNode *rajan=dummyNode;
        int carry=0;
        while(l1!=NULL && l2!=NULL) {
            int value=l1->val+l2->val+carry;
             carry=value/10;
            rajan->next=new ListNode(value%10);
            l1=l1->next;
            l2=l2->next;
            rajan=rajan->next;
        }
        if(l1!=NULL) {
            while(l1!=NULL) {
            int value=l1->val+carry;
         carry=value/10;
            rajan->next=new ListNode(value%10);
            l1=l1->next;
            rajan=rajan->next;
            }
        }
        if(l2!=NULL) {
            while(l2!=NULL) {
            int value=l2->val+carry;
            carry=value/10;
            rajan->next=new ListNode(value%10);
            l2=l2->next;
             rajan=rajan->next;
            }
        }
        // because we need to connect the last carry!
       if(carry!=0) rajan->next=new ListNode(carry);
        return dummyNode->next;
        }
    };