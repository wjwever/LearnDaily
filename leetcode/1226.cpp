/*************************************************************************
    > File Name: 1226.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时51分58秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class DiningPhilosophers {
public:
    int index = 0;
    std::mutex _mx;
    std::condition_variable _cv;
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        std::unique_lock<std::mutex> lock(_mx);
        _cv.wait(lock, [&] {return index % 5 == philosopher;});
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        ++index;
        _cv.notify_all();
    }
};
