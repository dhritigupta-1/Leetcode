class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> map;
    void func(string digits, string current, int start){
        if(start == digits.length()){
            ans.push_back(current);
            return;
        }
        string letter = map[digits[start]];
        for(char ch : letter) func(digits, current+ch, start+1);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        func(digits, "", 0);
        return ans;
        
    }
};