/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    // helper function to getLength for a LL
    int getLength(ListNode* head){
        if(head == NULL){
            return 0;
        }
        
        int len = 0;
        while(head != NULL){
            head = head->next;
            len++;
        }
        
        return len;
    }
    
    // helper function that returns the head of a LL shifted by "shift" units
    ListNode* getShiftedHead(ListNode* head, int shift){
        if(shift == 0){
            return head;
        }
        while(shift--){
            head = head->next;
        }
        return head;
    }
    
    // this will add the same length lists
    ListNode* addSameLengthLists(ListNode* a, ListNode* b, int &carry){
        ListNode* res = new ListNode(-1);
        
        if(a == NULL) return b;
        if(b == NULL) return a;
        if(a == NULL && b == NULL) return NULL;
        
        res->next = addSameLengthLists(a->next, b->next, carry);
        
        int sum = a->val + b->val + carry;
        carry = sum / 10;
        int finalValue = sum % 10;
        
        res->val = finalValue;
        return res;
    }
    
    ListNode* getNode(int data){
        ListNode* newNode = new ListNode(data);
        newNode->next = NULL;
        return newNode;
    }
    
    void addExtraNodes(ListNode* head, ListNode* shiftedHead, ListNode** resNode, int &carry){
        if(head == shiftedHead) return ;
        
        addExtraNodes(head->next, shiftedHead, resNode, carry);
        
        int sum = head->val + carry;
        carry = sum / 10;
        int finalValue = sum % 10;
        
        auto x = new ListNode(finalValue);
        
        x->next =  *resNode;
        *resNode = x; 
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode* res = new ListNode(-1);
        
        //get lengths for both the arrays
        int length1 = getLength(l1);
        int length2 = getLength(l2);
        
        // always good to create a copy.
        auto copyL2 = l2;
        auto copyL1 = l1;
        
        // traverse one of the linked lists, until they are of the same length
        copyL1 = length1 > length2 ? getShiftedHead(copyL1, abs(length1 - length2)) : copyL1;
        copyL2 = length2 > length1 ? getShiftedHead(copyL2, abs(length2 - length1)) : copyL2;
        
        // create a carry variable here and pass it as reference, so the carry is propagated correctly.
        int carry = 0;
        ListNode * sameLengthSum = addSameLengthLists(copyL1, copyL2, carry);
        
        
        ListNode * res;
        if(length1 > length2){
           addExtraNodes(l1, copyL1, &sameLengthSum, carry);
        } else{
         addExtraNodes(l2, copyL2, &sameLengthSum, carry);
        }
        
        if(carry == 1){
            auto extraNode = new ListNode(1);
            extraNode->next = sameLengthSum;
            return extraNode;
        }
        
        return sameLengthSum;
    
    }
};