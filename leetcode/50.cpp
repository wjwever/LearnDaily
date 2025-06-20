/*************************************************************************
    > File Name: leetcode/50.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月20日 星期五 11时00分04秒
 ************************************************************************/
#if 0
class Solution {
public:
    double myPow(double x, int n) {
       if (n >= 0)  {
            return pow(x, n);
       } else {
            return 1.0 / pow(x, -n);
       } 
    }

    double pow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        } 
        if (n == 1) {
            return x;
        }
        double val = pow(x, n / 2) ;
        return val * val * pow(x, n % 2);
    }
};
#endif

class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

