/*************************************************************************
    > File Name: leetcode/1394.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月12日 星期六 08时51分13秒
 ************************************************************************/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::map<int, int> book;
        for (auto i : arr) {
            ++book[i];
        }
        for (auto it = book.rbegin(); it != book.rend(); ++it) {
            if (it->first == it -> second) {
                return it->first;
            }
        }
        return -1;
    }
};
