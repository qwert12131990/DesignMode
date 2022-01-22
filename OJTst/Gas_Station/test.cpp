class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = min(gas.size(), cost.size());

        int idx = -1;
        vector<int> tmpVect(n, 0);
        
        for(int i=0; i<n; i++){
            tmpVect[i] = gas[i] - cost[i];
        }
        
        for(int i=0; i<n; i++){
            int tmpCost = 0;
            int j = i;
            do{
                //cout<<"i:"<<i<<" j:"<<j<<" cost:"<<tmpVect[j]<<endl;
                tmpCost += tmpVect[j];
                j = (++j) % n;
            }while(j!=i && tmpCost >= 0);
            
            //cout<<"idx:"<<i<<" i:"<<i<<" j:"<<j<<" tmpcost:"<<tmpCost<<endl;
            if (j==i && tmpCost >= 0){
                idx = i;
                break;
            }
        }
        return idx;
    }
};