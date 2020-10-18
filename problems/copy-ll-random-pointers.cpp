/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

// https://leetcode.com/problems/copy-list-with-random-pointer/submissions/
class Solution {
public:
    map<Node*,Node*> mapper;
    map<Node*, bool> visited;
    
    
    
   
    void dfs(Node * startNode){
         
    }
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        auto cp = head;
        Node* newHead;
        bool flag = 0;
        // interleave the lls
        while(cp){
            Node* copyNode = new struct Node(cp->val, NULL, NULL);
            if(!flag){
                flag = 1;
                newHead = copyNode;
            }
            copyNode->next = cp->next;
            cp->next = copyNode;
            
            cp = copyNode->next;
        }
        cp = head;
        while(cp){
            if(cp->random){
                cp->next->random = cp->random->next;
            }
            cp = cp->next->next;
        }
        cp = head;
        while(cp){
            auto copyNode = cp->next;
            cp->next = copyNode->next;
            copyNode->next = copyNode->next ? copyNode->next->next : NULL;
            
            cp = cp->next;
        }
        
        return newHead;
        
        
        
    }
};