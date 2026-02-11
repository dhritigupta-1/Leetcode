class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for(char st : s) map[st]++;
        priority_queue<pair<int, char>> pq;
        for(auto &p : map) pq.push({p.second, p.first});
        string res;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            res.append(top.first, top.second);
        }
        return res;
    }
};