class Solution {
public:
    bool possible(vector<int>& weights, int days, int mid) {
        int current = 0;
        int usedDays = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (mid >= current+weights[i]) {

                    current += weights[i];
                
            } else {
                
                usedDays ++;
                current=weights[i];
            }
        }
        if(usedDays<=days)return true;;
        return false;


    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++)
            sum += weights[i];
        int high = sum;
        int low = *max_element(weights.begin(), weights.end());
        int mini = sum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(weights, days, mid)) {
                mini = min(mini, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return mini;
    }
};