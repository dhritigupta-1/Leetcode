class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto s : nums){
            ans.push_back(to_string(s));
        }
        sort(ans.begin(), ans.end(), [](string& a, string& b){
            return a + b > b+a;
        });
        if(ans[0] == "0") return "0";
        string res;
        for(auto s : ans){
            res += s;
        }
        return res;
    }
};