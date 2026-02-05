class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        vector<string> ans = words;
        for(string &s : ans) reverse(s.begin(), s.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(words[i] == ans[j] && words[j] == ans[i]) count++;
            }
        }
        return count;
    }
};