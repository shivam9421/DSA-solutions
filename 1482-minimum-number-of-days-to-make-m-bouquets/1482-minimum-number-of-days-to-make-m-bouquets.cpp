class Solution {
public:
    bool possible(int day, int& m, int& k, vector<int>& bloomDay) {
        int count = 0;
        int n = bloomDay.size();
        int t_p_bouq = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                int p_bouq = count / k;
                t_p_bouq = t_p_bouq + p_bouq;
                count = 0;
            }
        }
        t_p_bouq+=(count/k);
        
        return t_p_bouq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long is_bouqformed=(long long)m*k;
        if (bloomDay.size() < is_bouqformed)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        while (low <=high) {
            int mid = low + (high - low) / 2;
            if (possible(mid, m, k, bloomDay)) {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};