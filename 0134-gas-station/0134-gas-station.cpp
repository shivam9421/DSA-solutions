class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int istravel_current=0;
        int istravel=0;
        int startindex=0;
        for(int i=0;i<cost.size();i++){
            int gain=gas[i]-cost[i];
            istravel+=gain;
            istravel_current+=gain;
            if(istravel_current<0){
                startindex=i+1;
                istravel_current=0;
            }
        }
        if(istravel<0)return -1;
        return startindex;
        
    }
};