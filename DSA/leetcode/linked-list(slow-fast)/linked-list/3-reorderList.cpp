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
    void reorderList(ListNode* head) {
        //find mid and split the array 
        //reverse the second half and keep slow->next = null
        //merge
        ListNode* fast = head;
        ListNode* slow= head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is at mid
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* revSH = reverse(secondHalf);
        merge(head, revSH);

        
    }

    void merge(ListNode* head, ListNode* revSH){
        ListNode* left = head;
        ListNode* right = revSH;
        ListNode* front;
        ListNode* front2;

        while(left && left->next && right ){
            front = left->next;
            left->next = right;
            front2 = right->next ;
            right->next = front;
            left = front;
            right = front2;
        }
            
    }
    
    ListNode* reverse(ListNode* part2){
        ListNode* curr = part2;
        ListNode* prev = nullptr;
        ListNode* front;
        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

};