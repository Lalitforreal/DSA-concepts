
//LC 142
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
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                break;
            }
        }
        
        if(!fast || !fast->next){
            return nullptr;
        }

        slow = head;
        //fast at the point where they both met
        while(slow!= fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};