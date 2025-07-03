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
    ListNode* merge_two_ll(ListNode* l1, ListNode* l2){
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }

        if(l1->val <= l2->val){
            l1->next = merge_two_ll(l1->next , l2);
            return l1;
        }
        else{
            l2->next = merge_two_ll(l1 , l2->next);
            return l2;
        }

        return nullptr;

    }

    ListNode* partition_and_merge(int start, int end, vector<ListNode*>& lists){
        if(start == end){
            return lists[start];
        }
        if( start > end){
            return nullptr;
        }
        int mid = (start + end) / 2;

        ListNode* l1 = partition_and_merge(start , mid , lists);
        ListNode* l2 = partition_and_merge(mid + 1, end , lists);

        return merge_two_ll(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0)
            return NULL;

        return partition_and_merge(0 , n-1 , lists);
    }
};