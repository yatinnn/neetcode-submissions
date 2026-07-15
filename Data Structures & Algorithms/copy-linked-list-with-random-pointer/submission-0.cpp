/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*iter=head;
        Node*front=iter;
        while(iter){
            front=iter->next;
            Node* copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        while(iter){
            if(iter->random!=NULL){
                iter->next->random=iter->random->next;
            }iter=iter->next->next;
        }
        iter=head;
        Node* pseudo=new Node(0);
        Node*dummy=pseudo;
        while(iter){
            front=iter->next->next;
            dummy->next=iter->next;
            iter->next=front;
            dummy=dummy->next;
            iter=iter->next;
        }
        return pseudo->next;
    }
};
