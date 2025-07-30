/*************************************************************************
    > File Name: leetcode/3439.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 10时44分21秒
 ************************************************************************/
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>  freeSpace;
        if (startTime[0] >  0) {
            freeSpace.push_back(startTime[0]);
        }
        for (int i = 0; i < endTime.size() - 1; ++i) {
            freeSpace.push_back(startTime[i+1] - endTime[i]);
        }
        if (eventTime > endTime.back()) {
            freeSpace.push_back(eventTime-endTime.back());
        }

/*
        for (auto f : freeSpace) {
            std::cout << "free:" << f << std::endl;
        }
*/

        int res = 0;
        for (int i = 0; i <= k and i < freeSpace.size(); ++i) {
            res += freeSpace[i];
        }

        int curRes = res;
        for (int i = 0; i < int(freeSpace.size()) -k - 1 ; ++i)  {
            curRes -= freeSpace[i];
            curRes += freeSpace[i + k + 1];
            res = max(res, curRes);
        }
        return res;
    }
};

