class Solution {
public:
    vector<vector<int>> generateMatrix(int n) { 
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int count=1;
        for(int layer=0 ;layer<=n+1/2;layer++){
            for(int left=layer;left<n-layer;left++){
                matrix[layer][left]=count++;
            }
            for(int top=layer+1;top<n-layer;top++){
                matrix[top][n-layer-1]=count++;
            }
            for(int right=n-layer-2;right>=layer;right--){
                matrix[n-layer-1][right]=count++;
            }
            for(int bottom=n-layer-2;bottom>=layer+1;bottom--){
                matrix[bottom][layer]=count++;
            }
        }
        return matrix;
        
    }
};