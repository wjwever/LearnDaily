/*************************************************************************
    > File Name: 1195.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月30日 星期三 21时50分16秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class FizzBuzz {
private:
    int n;
    std::mutex _mx;
    std::condition_variable _cv;
    bool _running = true;
    bool _print_other = true;
    int flag = 0;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            std::unique_lock<std::mutex> lock(_mx);
            _cv.wait(lock, [&]{return (_print_other == false && flag == 3) || _running == false;});
            if (_running == false)  break;
            std::cout << "fizz\n";
            printFizz();
            _print_other = true;
            _cv.notify_all();
        }
        std::cout << "exit f\n";
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(_mx);
            _cv.wait(lock, [&]{return (_print_other == false && flag == 5) || _running == false;});
            if (_running == false)  break;
            std::cout << "bizz\n";
            printBuzz();
            _print_other = true;
            _cv.notify_all();
        }
        std::cout << "exit b\n";
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(_mx);
            _cv.wait(lock, [&]{return (_print_other == false && flag == 15) || _running == false;});
            if (_running == false)  break;
            std::cout << "fizzbuzz\n";
            printFizzBuzz();
            _print_other = true;
            _cv.notify_all();
        }
        std::cout << "exit fb\n";
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(_mx);
        for (int i = 1; i <= n; ++i) {
            std::cout << i << std::endl;
            _cv.wait(lock, [&]{return _print_other == true;});
            if (i % 15 == 0) {
                flag = 15;
                _print_other = false;
            }  else if (i % 3 == 0) {
                flag = 3;
                _print_other = false;
            } else if (i % 5 == 0) {
                flag = 5;
                _print_other = false;
            }  else {
                flag = 0;
                _print_other = true;
                printNumber(i);
            }
            _cv.notify_all();
        } 
        _cv.wait(lock, [&]{return _print_other == true;});
        _running = false;
        _cv.notify_all();
    }
};
