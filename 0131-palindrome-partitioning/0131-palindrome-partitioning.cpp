class Solution {
public:
    bool Palindrome(string s, int low, int high){
        while(low < high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void func(string s, vector<vector<string>>& ans, vector<string> temp, int start){
        if(start == s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<s.length(); i++){
            if(Palindrome(s, start, i)){
                temp.push_back(s.substr(start, i-start+1));
                func(s, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(s, ans, temp, 0);
        return ans;
    }
};