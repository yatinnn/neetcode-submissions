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

    ListNode * merge(ListNode* A, ListNode* B){
        if(!A)return B;
        if(!B)return A;
        ListNode* ans=new ListNode;
        if(A->val<=B->val){
            ans->val=A->val;
           ans->next= merge(A->next,B);
        }
        else {
             ans->val=B->val;
           ans->next= merge(A,B->next);
        }
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        int end=n-1;
        while(end!=0){
            int start=0;
            int temp=end;
            while(start<temp){
                lists[start]=merge(lists[start],lists[temp]);
                start++;
                temp--;
                if(start>=temp){
                    end=temp;
                }
            }
        }
        return lists[0];
    }
};
