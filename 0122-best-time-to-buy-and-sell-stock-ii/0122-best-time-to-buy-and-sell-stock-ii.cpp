class Solution {
public: 
    int f(int i,vector<int>& prices){
        //base conditiion
        if(i==prices.size()) return 0;
        int profit = 0;
        if(prices[i] > prices[i - 1])  { 
            profit=prices[i]-prices[i-1];
        }
        return profit +f(i+1,prices);
    }
    int maxProfit(vector<int>& prices) {
        return f(1,prices);
    }
};