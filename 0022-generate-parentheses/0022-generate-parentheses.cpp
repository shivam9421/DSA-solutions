class Solution {
public:
    void backtrack(int open,int close,int &n,vector<string> &ans,string current){
        if(open==n && close==n ){
            ans.push_back(current);
            return;
            }
            if(open<n){
                backtrack(open+1,close,n,ans,current+'(');
            }
            if(close <open){
                backtrack(open,close+1,n,ans,current+')');
            }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        backtrack(0,0,n,ans,"");
        return ans;
        
    }
};