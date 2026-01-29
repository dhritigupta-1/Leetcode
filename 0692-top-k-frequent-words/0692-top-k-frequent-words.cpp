class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> map;
        for(auto ch : words)
            map[ch]++;
        vector<pair<string, int>> s;
        for(auto p : map)
            s.push_back(p);
        sort(s.begin(), s.end(), [](const auto a, const auto b){
            if(a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });
        vector<string> ans;
        for(int i=0; i<k; i++)
            ans.push_back(s[i].first);
        return ans;
    }
};