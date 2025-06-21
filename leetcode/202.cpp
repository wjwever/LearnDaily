class Solution {
public:
    bool isHappy(int n) {
        std::set<int> nums;
        while(true) {
            if (n == 1) {
                return true;
            }
            if (nums.count(n) == 1) {
                break;
            }
            nums.insert(n);
            n = fun(n);
        } 
        return false;
    }

    int fun(int n) {
        int res = 0;
        while(n > 0) {
            res += (n % 10)  * (n % 10);
            n /= 10;
        }
        return res;
    }
};
