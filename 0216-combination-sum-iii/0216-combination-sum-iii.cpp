class Solution {
public:
void sumpr(int a,vector<int>& stsmele,vector<vector<int>>&ans,int sum,int k,int n){
    if(n==sum &&k==0) {
        ans.push_back(stsmele);
        return;
    }
    if(k==0||sum>n ||a==10) return;
    ///1 .k-tracck 2 sum check 3.stsele ka funda 3.ans me push ka funda 4.a ko increase  ya decrease
    stsmele.push_back(a);
    sumpr(a+1,stsmele,ans,sum+a,k-1,n);
    stsmele.pop_back();
    sumpr(a+1,stsmele,ans,sum,k,n);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>stsmele;
        vector<vector<int>> ans;
        sumpr(1,stsmele,ans,0,k,n);
        return ans;

    }
};