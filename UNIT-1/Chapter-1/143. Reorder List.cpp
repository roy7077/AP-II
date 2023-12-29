/*----------------Method-1-------------*/
//Using Vector
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* h=head;
        while(h)
        {
            v.push_back(h);
            h=h->next;
        }
        
        bool flag=1;
        int cnt=0;
        int size=v.size();
        
        ListNode* TNode=NULL;
        ListNode* temp=head;
        while(cnt<size)
        {
            if(flag)
            {
                if(!TNode)
                TNode=temp;
                else
                {
                    TNode->next=temp; 
                    TNode=temp;
                }   
                
                temp=temp->next;
            }
            else
            {
                ListNode* topp=v.back();
                TNode->next=topp;
                TNode=topp;
                v.pop_back();
            }
            flag=(!flag);
            cnt++;
        }
        
        TNode->next=NULL;
    }
};


/*----------------Method-2-------------*/
//Using Stack
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* h=head;
        while(h)
        {
            v.push_back(h);
            h=h->next;
        }
        
        bool flag=1;
        int cnt=0;
        int size=v.size();
        
        ListNode* TNode=NULL;
        ListNode* temp=head;
        while(cnt<size)
        {
            if(flag)
            {
                if(!TNode)
                TNode=temp;
                else
                {
                    TNode->next=temp; 
                    TNode=temp;
                }   
                
                temp=temp->next;
            }
            else
            {
                ListNode* topp=v.back();
                TNode->next=topp;
                TNode=topp;
                v.pop_back();
            }
            flag=(!flag);
            cnt++;
        }
        
        TNode->next=NULL;
    }
};
