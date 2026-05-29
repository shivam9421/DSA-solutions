class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int maxi=0;
        while(i<j){
            int area=0;
            if(height[i]<=height[j]){
                area=height[i]*(j-i);
                i++;
               
            }
            else if(height[j]<height[i] && i!=j){
                area=height[j]*(j-i);
                j--;
               
            }
            
            maxi=max(maxi,area);
        }
        return maxi;
    }
};