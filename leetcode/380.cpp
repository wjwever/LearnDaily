class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (_positions.count(val)) {
            return false;
        }
        _positions[val] = _datas.size();
        _datas.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!_positions.count(val)) {
            return false;
        }
        int pos = _positions[val]; 
        int len = _datas.size();
        _datas[pos] = _datas[len-1];
        _positions[_datas[pos]] = pos;
        
        _datas.pop_back();
        _positions.erase(val);
        return true;
    }
    
    int getRandom() {
        int id = rand() % _datas.size();
        return _datas[id];
    }
    std::unordered_map<int, int> _positions;
    std::vector<int> _datas;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
