class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int curIdx = 0;
        int temp = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i] - cost[i];
            temp +=  gas[i] - cost[i];
            if (temp < 0) {
                curIdx = i + 1;
                temp = 0;
            } 
            
        }
        if (totalGas < 0) {
            return -1;
        }
        return curIdx % gas.size();
    }
};
