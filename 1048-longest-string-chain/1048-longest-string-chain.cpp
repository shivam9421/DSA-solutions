class Solution {
public:
    // Compact standalone comparison function
static bool compareByLength(const string &a, const string &b)
 { return a.size() < b.size(); }
    bool f(string &words2,string words1 ){
        int n1=words1.size();
        int n2=words2.size();
        int p=0;
        for(int j=0;j<n2&& p < n1;j++ ){
            if(words1[p]==words2[j]){
                p++;
            }
        }
        if(p==n1 && n2-n1==1)return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compareByLength);
        int n=words.size();
        vector<int>dp(n,1);
        int lastindex=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(1+dp[pre]>dp[i]&&f(words[i],words[pre])){
                    dp[i]=1+dp[pre];
                }
            }
            if(dp[i]>maxi){
                maxi=max(maxi,dp[i]);
                lastindex=i;
            }
        }
        return dp[lastindex];
    }
};