class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        int n=cardpoints.size();
        int i=0;
        int j=n-1;
        int sumtotal=0;
        int sumleft=0;
        int sumright=0;
        int p=k;
        while(p>0){
            sumleft=sumleft+cardpoints[i];
            i++;
            sumtotal=max(sumtotal,sumleft);
            p--;
        }
        while(k>0){
            int sum=0;
            i--;
            sumleft=sumleft-cardpoints[i];
            sumright=sumright+cardpoints[j];
            sum=sumleft+sumright;
            sumtotal=max(sumtotal,sum);
            
            j--;
            k--;

        }

      
        return sumtotal;
        
    }
};