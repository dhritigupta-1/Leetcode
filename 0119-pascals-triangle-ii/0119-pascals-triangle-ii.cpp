class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1);
        for(int i=1; i<rowIndex; i++){
            long long prev = row[i-1];
            row[i] = prev * (rowIndex - i + 1) / i;
        }
        return row;
    }
};