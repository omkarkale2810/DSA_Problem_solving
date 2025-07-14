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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        string s = "";

        while(head){
            s += to_string(head->val);
            head = head->next;
        }

        int n = s.length();
        int pow2 = 0;

        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '1'){
                int curr = 1 << pow2;
                ans += curr;
            }
            pow2++;
        }

        return ans;

    }
};