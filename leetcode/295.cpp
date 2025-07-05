class MedianFinder {
public:
    std::priority_queue<int, std::vector<int>, std::less<int>> _queue1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> _queue2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int left = INT_MIN;
        int right = INT_MAX;

        if (_queue1.size()) {
            left = _queue1.top();
        }
        if (_queue2.size()) {
            right = _queue2.top();
        }

        if (num >= right) {
            //std::cout << "add2 " << num << std::endl;
            _queue2.push(num);
        } else {
            //std::cout << "add1 " << num << std::endl;
            _queue1.push(num);
        }

        if (_queue1.size() > _queue2.size() + 1) {
            auto num = _queue1.top();
            _queue1.pop();
            _queue2.push(num);
        }
        if (_queue2.size() > _queue1.size() + 1) {
            auto num = _queue2.top();
            _queue2.pop();
            _queue1.push(num);
        }
        //std::cout << "size:" << _queue1.size() << " " << _queue2.size() << std::endl;
    }
    
    double findMedian() {
        if (_queue1.size() == _queue2.size()) {
            return _queue1.top() * 0.5 + _queue2.top() * 0.5;
        } else if (_queue1.size() > _queue2.size()) {
            return _queue1.top();
        } else {
            return _queue2.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
