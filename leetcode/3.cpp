/*************************************************************************
    > File Name: 3.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 13时44分00秒
 ************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0, tail = 0;
        map<char, int> pos;
        int curMax = 0;
        while(head < s.size()) {
            if (pos.count(s[head]) == false) {
                pos[s[head]] = head;
                curMax = max(curMax, head - tail + 1);
                std::cout << "1" << head << " " << tail << " " << curMax << "\n";
                ++head;
            } else {
                tail = max(tail, pos[s[head]] + 1);
                curMax = max(curMax, head - tail + 1);
                std::cout << "2" << head << " " << tail << " " << curMax << "\n";
                pos[s[head]] = head;
                ++head;
            }
        }
        return curMax;
    }
};
