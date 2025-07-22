class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> m ;
        int left = 0;
        int result = 0;
        for (int right=0; right<s.size(); right++)
        {
            m[s[right]]++;
            while( m[s[right]] > 1)
            {
                m[s[left]]--;
                left +=1;
        }
        result = max(result , (right-left) + 1);
        }
        return result;
    }
};