// Time complexity - O(N+M)
// Space complexity- O(1)
class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        
        while(head1 and head2)
        {
            if(head1->val<head2->val)
            {
                if(!ansHead)
                {
                    ansHead=head1;
                    ansTail=head1;
                }
                else
                {
                    ansTail->next=head1;
                    ansTail=head1;
                }
                head1=head1->next;
            }
            else
            {
                if(!ansHead)
                {
                    ansHead=head2;
                    ansTail=head2;
                }
                else
                {
                    ansTail->next=head2;
                    ansTail=head2;
                }
                head2=head2->next;
            }
        }
        
        while(head1)
        {
            if(!ansHead)
            {
                ansHead=head1;
                ansTail=head1;
            }
            else
            {
                ansTail->next=head1;
                ansTail=head1;
            }
            head1=head1->next;
        }
        
        while(head2)
        {
            if(!ansHead)
            {
                ansHead=head2;
                ansTail=head2;
            }
            else
            {
                ansTail->next=head2;
                ansTail=head2;
            }
            head2=head2->next;
        }
        
        return ansHead;
    }
};