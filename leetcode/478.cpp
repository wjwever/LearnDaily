/*************************************************************************
    > File Name: leetcode/478.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 13时19分34秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

#if 0
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        _r = radius;
        _x = x_center;
        _y = y_center;
    }

    vector<double> randPoint() {
        while (true) {
            double randx = static_cast<double>(std::rand()) / RAND_MAX;
            double randy = static_cast<double>(std::rand()) / RAND_MAX;
            double x = 2  * _r * randx   - _r;
            double y = 2  * _r * randy   - _r;
            if ( x * x + y * y < _r * _r) {
                return {_x + x, _y + y};
            }
        }
    }
    int _x;
    int _y;
    int _r;
};
#endif

class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center): dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}

    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return {xc + x, yc + y};
            }
        }
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
