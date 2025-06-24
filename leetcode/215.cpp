class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;    
        for (auto n : nums) {
            if (pq.size() < k) {
                pq.push(n);
                std::cout << "push" << n << std::endl;
            } else if (n > pq.top()) {
                std::cout << "pop:" << pq.top() << std::endl;
                pq.pop();
                pq.push(n);
                std::cout << "push" << n << std::endl;
            }
        }
        return pq.top();
    }
};
