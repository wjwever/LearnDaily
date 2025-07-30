/*************************************************************************
    > File Name: leetcode/1116.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月28日 星期一 22时32分30秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class ZeroEvenOdd {
private:
    int n;

    int index = 1;
    bool print0 = true;
    std::mutex _mx;
    std::condition_variable _cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
       while (true) {
         std::unique_lock <std::mutex> lock(_mx);
         _cv.wait(lock, [this]{return print0 || index > n;});
         if (index > n) break;
         std::cout << 0 << "\n";
         printNumber(0);
         print0 = false;
         _cv.notify_all();
       }
       std::cout << "exit 0\n";
    }

    void even(function<void(int)> printNumber) {
    while(true) {
         std::unique_lock <std::mutex> lock(_mx);
         _cv.wait(lock, [this]{return index > n || (print0 == false and index % 2 == 0);});
         if (index > n)  break;
         std::cout << index << "\n";
         printNumber(index);
         ++index;
         print0 = true;
         _cv.notify_all();
        }
       std::cout << "exit 2\n";
    }

    void odd(function<void(int)> printNumber) {
        while(true) {
            std::unique_lock <std::mutex> lock(_mx);
            _cv.wait(lock, [this]{return index > n || (print0 == false and index % 2 == 1);});
            if (index > n)  break;
            printNumber(index);
            std::cout << index << "\n";
            ++index;
            print0 = true;
            _cv.notify_all();
       }
       std::cout << "exit 1\n";
    }
};
