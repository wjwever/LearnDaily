class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        for (int i = 0; i < n; ++i) {
            if (i > 0 and ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        int sum = 0, right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n -1 and ratings[i] > ratings[i + 1]) {
                right += 1;
            } else {
                right = 1;
            }
            sum += max(right, left[i]);
        }
        return sum;
    }
};
