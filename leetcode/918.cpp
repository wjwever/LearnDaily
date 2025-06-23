class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int start = 0;
        int Max = INT_MIN;
        do {
            int  curMax = 0;
            bool addOne = true;
            for (int i = 0; i < nums.size(); ++i) {
                curMax += nums[ (start + i) % nums.size()];
                Max = max(Max, curMax);
                //std::cout << start << "\t" << i  << curMax <<"\t" << Max << std::endl;
                if (curMax <= 0) {
                    start =  start + i + 1;
                    addOne = false;
                    break;
                }
            }
            if (addOne == true) {
                ++start;
            }
        } while(start < nums.size());
        
        return Max;
    }
};
