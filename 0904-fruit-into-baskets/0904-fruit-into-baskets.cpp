class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxtree=0;
        int count=0; 
        unordered_map<int,int> mpp;
        int j=0;
        int i=0;
        while(j<n){
            mpp[fruits[j]]++;
            while (mpp.size() > 2) {
                mpp[fruits[i]]--;
                if (mpp[fruits[i]] == 0)
                    mpp.erase(fruits[i]);
                i++;
            }
            
            count=j-i+1;
            maxtree=max(count,maxtree);
            j++;
        }
    return maxtree;
    }
};