/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        
        // no loop case;
        if(slow != fast || !slow || !fast || !fast->next) return NULL;
        
        
        cout <<slow->val <<endl;
        auto a = head;
        while(a != slow){
            a = a->next;
            slow = slow->next;
        }
        return a;
        
        
    }
};