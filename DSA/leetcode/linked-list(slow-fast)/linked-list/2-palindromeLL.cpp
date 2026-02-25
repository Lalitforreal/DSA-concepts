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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }

        temp = head;
        for(int i = 0; i < count / 2 ; i++){
            temp = temp->next;
        }
        ListNode* part2 = temp;

        ListNode* left = head;
        ListNode* right = reverse(part2);
        while(left != part2 && part2){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
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