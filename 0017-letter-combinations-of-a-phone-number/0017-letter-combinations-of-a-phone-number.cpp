class Solution {
public:
    vector<string> res;
    unordered_map<char, string> map;
    void Func(string digits, string current, int start){
        if(start == digits.size()){
            res.push_back(current);
            return;
        }
        string letters = map[digits[start]];
        for(char ch : letters) Func(digits, current+ch, start+1);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        Func(digits, "", 0);
        return res;
    }
};