class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int j = 0, sum = 0, count = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(i-j+1==k){
                double avg = (double) sum/k;
                if(avg >= threshold) count++;
                sum -= arr[j]; j++;
            }
        }
        return count;
    }
};