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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)return head;
        ListNode* dummy=new ListNode;
        dummy->next=head;
        ListNode* preNode=dummy;
        ListNode* currNode=dummy;
        ListNode* nextNode=dummy;
        int cnt=0;
        while(currNode->next){
            currNode=currNode->next;
            cnt++;
        }

        while(cnt>=k){
            currNode=preNode->next;
            nextNode=currNode->next;
            for(int i=1;i<k;i++){
                currNode->next=nextNode->next;
                nextNode->next=preNode->next;
                preNode->next=nextNode;
                nextNode=currNode->next;
            }cnt-=k;
            preNode=currNode;
        }
        return dummy->next;
    }
};
