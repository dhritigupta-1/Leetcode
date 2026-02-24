class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> arr(nums.begin(), nums.end());
        vector<int> L(n), R(n);
        vector<bool> dead(n, false);

        for (int i = 0; i < n; i++) {
            L[i] = i - 1;
            R[i] = i + 1;
        }

        // Min heap: (sum, index)
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({arr[i] + arr[i+1], i});
        }

        // Count decreasing adjacent pairs
        int bad = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1]) bad++;
        }

        int ops = 0;

        while (bad > 0) {

            auto [sum, i] = pq.top();
            pq.pop();

            int j = R[i];

            // Skip invalid pairs
            if (j >= n || dead[i] || dead[j]) continue;
            if (arr[i] + arr[j] != sum) continue;

            // Remove old bad contributions
            if (L[i] != -1 && !dead[L[i]] && arr[L[i]] > arr[i])
                bad--;

            if (arr[i] > arr[j])
                bad--;

            if (R[j] < n && !dead[R[j]] && arr[j] > arr[R[j]])
                bad--;

            // Merge
            arr[i] = sum;
            dead[j] = true;

            R[i] = R[j];
            if (R[j] < n)
                L[R[j]] = i;

            // Add new bad contributions
            if (L[i] != -1 && !dead[L[i]] && arr[L[i]] > arr[i])
                bad++;

            if (R[i] < n && !dead[R[i]] && arr[i] > arr[R[i]])
                bad++;

            // Push new adjacent sums
            if (L[i] != -1 && !dead[L[i]])
                pq.push({arr[L[i]] + arr[i], L[i]});

            if (R[i] < n && !dead[R[i]])
                pq.push({arr[i] + arr[R[i]], i});

            ops++;
        }

        return ops;
    }
};