class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<string> dfs(string s, unordered_set<string>& dict) {
        if (map.count(s)) return map[s];
        vector<string> result;
        if (s.empty()) {
            result.push_back("");
            return result;
        }
        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> sublist = dfs(s.substr(i), dict);

                for (string sub : sublist) {
                    result.push_back(word + (sub.empty() ? "" : " " + sub));
                }
            }
        }
        return map[s] = result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
        
    }
};