class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        int Max = 0;
        for (int i = 0; i  < n - 1; ++i) {
           Max = max(height[i], Max) ;
           left[i + 1] = Max;
        }
        Max = 0;
        for(int i = n - 1; i > 0; --i) {
            Max = max(height[i], Max);
            right[i - 1] = Max;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int curRes = max(0, min(left[i], right[i]) - height[i]);
            //std::cout << i << " " << left[i] << " " << right[i] << " " << height[i] << std::endl;
            res += curRes;
        }
        return res;
    }
};
