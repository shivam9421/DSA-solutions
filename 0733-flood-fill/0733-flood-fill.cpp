class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>ans;
        ans=image;
        queue<pair<pair<int,int>,int>> q;
        ans[sr][sc]=color;
        vis[sr][sc]=1;
        q.push({{sr,sc},image[sr][sc]});
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int intialpixelvalue=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&ans[nrow][ncol]==intialpixelvalue&&vis[nrow][ncol]!=1){
                    ans[nrow][ncol]=color;
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},intialpixelvalue});
                }
            }
        }
        return ans;
    }
};