class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumcost=0;
        int sumgas=0;
        for(int i=0;i<gas.size();i++){
            sumcost+=cost[i];
            sumgas+=gas[i];
        }
        if(sumgas<sumcost)return -1;
        int istravel=0;
        int startindex=0;
        for(int i=0;i<cost.size();i++){
            istravel+=gas[i]-cost[i];
            if(istravel<0){
                startindex=i+1;
                istravel=0;
            }
        }
        return startindex;
        
    }
};