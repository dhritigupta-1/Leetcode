class Solution {
public:
    bool Palindrome(string s, int low, int high)
    {
        while(low < high)
        {
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    void Func(string s, vector<string>&temp, vector<vector<string>>& res, int start)
    {
        if(start == s.length())
        {
            res.push_back(temp);
            return;
        }
        for(int i=start; i<s.length(); i++)
        {
            if(Palindrome(s, start, i))
            {
                temp.push_back(s.substr(start, i - start + 1));
                Func(s, temp, res, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        Func(s, temp, res, 0);
        return res;
    }
};