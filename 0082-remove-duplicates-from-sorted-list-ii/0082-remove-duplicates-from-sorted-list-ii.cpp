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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        unordered_map<int, int> map;
        for(int it : ans) map[it]++;
        vector<int> res;
        for(auto it: map){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        ListNode* dummy = new ListNode(0);
        temp = dummy;
        sort(res.begin(), res.end());
        for(int x : res){
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        return dummy->next;
        
    }
};