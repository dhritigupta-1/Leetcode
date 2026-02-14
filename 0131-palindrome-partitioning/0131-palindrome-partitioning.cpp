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
    void Func(string s, vector<string> temp, vector<vector<string>>& res, int start){
        if(start == s.length()){
            res.push_back(temp);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(Palindrome(s, start, i)){
                temp.push_back(s.substr(start, i - start + 1)); // choice
                Func(s, temp, res, i+1);
                temp.pop_back(); // bactracking
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        Func(s, temp, res, 0);
        return res;
    }
};