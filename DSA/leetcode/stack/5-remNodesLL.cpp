//LC 2487

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            while(!st.empty() && temp->val > st.top()->val){
                st.pop();
            }

            st.push(temp);
            temp = temp->next;
        }

        ListNode* final = curr;
        while(!st.empty()){
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        curr->next = nullptr; //very imp

        //reverse the list
        ListNode* prev = nullptr;
        temp = final->next;
        while(temp ){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        
        return prev;
    }
};