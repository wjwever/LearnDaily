/*************************************************************************
    > File Name: leetcode/1115.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 22时08分15秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class FooBar {
private:
    int n;
    int index = 0;
    std::mutex _mx;
    std::condition_variable _cv;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(_mx);
            _cv.wait(lock, [&]{return index % 2 == 0;});

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++index;
            _cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(_mx);
            _cv.wait(lock, [&]{return index % 2 == 1;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++index;
            _cv.notify_all();
        }
    }
};
