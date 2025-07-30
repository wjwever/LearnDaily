/*************************************************************************
    > File Name: 1117.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时51分21秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class H2O {
public:
    int num_h = 0;
    std::mutex _mx;
    std::condition_variable _cv;
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock (_mx);
        _cv.wait(lock, [&]{return num_h < 2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++num_h;
        _cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock (_mx);
        _cv.wait(lock, [&]{return num_h == 2;});

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        num_h = 0;
        _cv.notify_all();
    }
};
