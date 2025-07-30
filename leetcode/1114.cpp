/*************************************************************************
    > File Name: leetcode/1114.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 22时00分02秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Foo {
public:
    int num = 0;
    std::mutex _mx;
    std::condition_variable _cv;
    Foo() {

    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(_mx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++num;
        _cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(_mx);
        _cv.wait(lock, [this](){return this->num == 1;});
        // printFirst() outputs "first". Do not change or remove this line.
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++num;
        _cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(_mx);
        _cv.wait(lock, [this](){return this->num == 2;});

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        ++num;
        _cv.notify_all();
    }
};
