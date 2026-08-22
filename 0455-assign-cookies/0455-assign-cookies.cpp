class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0|| g.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int max_cookies_child=0;
        int j=s.size()-1;
        for(int i=g.size()-1;i>=0;i--){
            if(j>=0){
            if(g[i]<=s[j]){
                max_cookies_child+=1;
                j--;
            }}
        }
        return  max_cookies_child;
        
    }
};