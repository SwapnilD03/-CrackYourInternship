class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> difference(n);
        int totalGas=0,totalCost=0;
        for(int i=0;i<n;i++){
           totalGas+=gas[i];
           totalCost+=cost[i];
           difference[i]=gas[i]-cost[i];
        }

        if(totalGas<totalCost){
            return -1;
        }

        int total=0;
        int ind=0;

        for(int i=0;i<n;i++){
            total+=difference[i];
            if(total<0){
                total=0;
                ind=i+1;
            }
            
            
        }

        return ind;
    }
};
