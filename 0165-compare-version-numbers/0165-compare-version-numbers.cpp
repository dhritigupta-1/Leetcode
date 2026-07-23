class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j=0;
        int n = version1.size();
        int m = version2.size();
        while(i<n || j<m){
            int a = 0;
            while(i<n && version1[i] != '.'){
                a = a * 10 + (version1[i] - '0');
                i++; 
            }
            int b = 0;
            while(j<m && version2[j] != '.'){
                b = b * 10 + (version2[j] - '0');
                j++; 
            }
            if(a > b) return 1;
            else if(a < b) return -1;
            i++;
            j++;
        }
        return 0;
    }
};