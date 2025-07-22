class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> map;
        for(char sb : s)
            map[sb]++;
        for(char sb : t)
            map[sb]--;
        for(char sb : t)
        {
            if(map[sb] < 0)
                return false;
        }
        return true;
    }
};