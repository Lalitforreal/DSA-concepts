// LC 23
class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* a,const ListNode* b ){
            return a->val > b->val; //min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>, cmp> pq;
        for(auto i : lists){
            if( i !=nullptr){
                pq.push(i);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(!pq.empty()){
            ListNode* min = pq.top();
            curr->next = min;
            curr = curr->next;
            pq.pop();

            if(curr && curr->next){
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};