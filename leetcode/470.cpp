/*************************************************************************
    > File Name: leetcode/470.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月11日 星期五 16时57分18秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = 0, b = 0;
        while ( (a = rand7()) > 2) ;
        while ( (b = rand7()) > 5) ;

        if (a == 1) {
            return 5 + b;
        } else {
            return b;
        }
    }
};
