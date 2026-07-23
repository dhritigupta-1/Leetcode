class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(auto it : arr) map[it]++;
        vector<int> ans;
        for(auto i : map) ans.push_back(i.second);
        for(int i=0; i<ans.size(); i++){
            for(int j=i+1; j<ans.size(); j++){
                if(ans[i] == ans[j]) return false;
            }
        }
        return true;
    }
};