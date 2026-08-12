class Solution {
public:
    vector<int>dp;
    int f(int i,string &s){
        //base
        if (i >= s.size())
            return 1;
        if (s[i] == '0')
            return 0;  
        if(dp[i]!=-1)return dp[i];      
        int c = f(i + 1, s);
        int d = 0;
        if(i<s.size()-1){
            int a=((s[i] - '0') *10+(s[i+1] - '0'));
            if(a<=26 &&a>=10){
                d=f(i+2,s);
            }
        }
        return dp[i]=c+d;
    }
    int numDecodings(string s) {
        
        int n=s.size();
        dp.assign(n,-1);
        int a=f(0,s);
        return a;
    }
};