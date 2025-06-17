class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int current = (right - left) * min(height[left], height[right]);
            //std::cout << current << std::endl;
            maxArea = max(maxArea, current);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};
