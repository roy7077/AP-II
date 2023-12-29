/*-------------------Method-1-------------*/
//Recursion
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    
    pair<bool,ListNode*> help(ListNode* head,int pre)
    {
        //base case
        if(!head)
        return {0,head};
        
        //small calculation
        //recursive calls
        if(head->val==pre)
        {
            ListNode* temp=head->next;
            delete head;
            head=temp;
            pair<bool,ListNode*> temp2=help(head,pre);
            
            return {1,temp2.second};
        }
    
        pair<bool,ListNode*> temp=help(head->next,head->val);
        
        if(temp.first)
        {
            delete head;
            return {0,temp.second};
        }
        head->next=temp.second;
        return {0,head};
        
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !(head->next)) 
        return head;

        pair<bool,ListNode*> ans=help(head,-1e9);
        return ans.second;
    }
};

/*-------------------Method-2-------------*/
//Iterative
//Time complexity - O(N)
//Space complexity- O(1)
class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !(head->next)) 
        return head;

        ListNode *curr = head, *prev = NULL;
        ListNode *r_head = NULL, *r_tail = NULL;

        int cnt = 0;
        while (curr) 
        {
            if(!prev || prev->val == curr->val) 
            ++cnt;
                else {
                if (cnt < 2) 
                {
                    if (r_head == NULL) 
                    {
                        r_head = new ListNode(prev->val);
                        r_tail = r_head;
                    } else {
                        r_tail->next = new ListNode(prev->val);
                        r_tail = r_tail->next;
                    }
                }
                cnt = 1;
            }
            prev = curr;
            curr = curr->next;
        }
        // To check for the last element of linked list
        if (cnt < 2 && prev != NULL) {
            if (r_head == NULL)
            r_head = new ListNode(prev->val);
            else
            r_tail->next = new ListNode(prev->val);
        
        }
        return r_head;
    }
};