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
     ListNode* middleHead(ListNode* head){
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }    

    ListNode* reverseHead(ListNode* head){
        ListNode*newHead=NULL;
        while(head){
            ListNode* nextHead=head->next;
            head->next=newHead;
            newHead=head;
            head=nextHead;
        }
        return newHead;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return ;
        ListNode* middle=middleHead(head);
        ListNode* reverse=reverseHead(middle);
        ListNode* left=head->next;
        for(int i=0;left!=reverse;i++,head=head->next){
            if(i%2){
                head->next=left;
                left=left->next;
            }
            else{
                head->next=reverse;
                reverse=reverse->next;
            }
        }
    }
};
