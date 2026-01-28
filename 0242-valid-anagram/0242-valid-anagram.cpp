class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> map;
        for(auto sb : s)
            map[sb]++;
        for(auto sb : t)
            map[sb]--;
        for(auto sb : t){
            if(map[sb] < 0)
                return false;
        }
        return true;
    }
};