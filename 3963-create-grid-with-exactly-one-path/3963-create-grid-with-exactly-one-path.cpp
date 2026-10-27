class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string ans="";
        for(int i=0;i<n;i++)ans+="#";
        vector<string> final_ans (m,ans);
        for(int i=0;i<n;i++)final_ans[0][i]='.';
        for(int j=0;j<m;j++)final_ans[j][n-1]='.';
        return final_ans;

    }
};