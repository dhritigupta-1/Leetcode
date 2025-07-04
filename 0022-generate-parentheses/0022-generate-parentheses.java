class Solution {
    void Func(int n, String s, List<String>res, int open, int close)
    {
        if(s.length() == 2*n)
        {
            res.add(s);
            return;
        }
        if(open < n)
            Func(n, s+"(", res,  open+1, close);
        if(close < open)
            Func(n, s+")", res,  open, close+1);
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        Func(n, "", res, 0, 0);
        return res;
    }
}