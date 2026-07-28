class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        for(int i=0; i<senate.size(); i++){
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int a = r.front();
            r.pop();
            int b = d.front();
            d.pop();
            if(a < b) r.push(a + senate.size());
            else d.push(b + senate.size());
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};