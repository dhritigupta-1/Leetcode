class Solution {
public:
    void Func(int n, string s, vector<string>& res, int open, int close)
    {
        if(s.length() == 2*n)
        {
            res.push_back(s);
            return;
        }
        if(open < n)
            Func(n, s+ "(", res, open+1, close);
        if(close < open)
            Func(n, s+")", res, open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        Func(n,"", res,0,0);
        return res;
    }
};