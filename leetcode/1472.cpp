/*************************************************************************
    > File Name: leetcode/1472.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月15日 星期二 21时56分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class BrowserHistory {
public:
    vector<string> pages;
    int index = 0;
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        index = 0;
    }

    void visit(string url) {
        if (index == pages.size() - 1) {
            pages.push_back(url);
            ++index;
        } else {
            pages[++index] = url;
            pages.resize(index + 1);
        }
        #if 0
        std::cout << "visit index:" << index << std::endl;
        for (auto& str : pages) {
            std::cout << str << '\t';
        }
        std::cout << '\n';
        #endif
    }

    string back(int steps) {
        index -= steps;
        if (index < 0) {
            index = 0;
        }
        #if 0
        std::cout << "back " << steps  << " index:" << index  << std::endl;
        for (auto& str : pages) {
            std::cout <<  str << '\t';
        }
        std::cout << '\n';
        #endif
        return pages[index];
    }

    string forward(int steps) {
        index += steps;
        if (index >= pages.size()) {
            index = pages.size() - 1;
        }

        #if 0
        std::cout << "forward" << steps  << " index:" << index  << std::endl;
        for (auto& str : pages) {
            std::cout << str << '\t';
        }
        std::cout << '\n';
        #endif

        return pages[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
