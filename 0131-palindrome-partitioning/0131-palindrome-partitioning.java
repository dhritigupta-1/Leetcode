class Solution {
    boolean Palindrome(String s, int start, int i)
    {
        while(start < i)
        {
            if(s.charAt(start) != s.charAt(i))
                return false;
            start++;
            i--;
        }
        return true;
    }
    void Func(String s, List<String> temp, List<List<String>> res, int start)
    {
        if(start == s.length())
        {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i=start; i<s.length(); i++)
        {
            if(Palindrome(s,start,i))
            {
                temp.add(s.substring(start, i+1));
                Func(s, temp, res, i+1);
                temp.remove(temp.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        Func(s, new ArrayList<>(), res, 0);
        return res;
    }
}