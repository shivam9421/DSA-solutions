class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];
        int a = nums.size();

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                sum += nums[i];
            } 
            else {
                a = i;
                break;
            }
        }

        int maxi = sum;

        while (true) {
            bool found = false;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == maxi) {
                    maxi++;
                    found = true;
                    break;
                }
            }

            if (!found)
                break;
        }

        return maxi;
    }
};