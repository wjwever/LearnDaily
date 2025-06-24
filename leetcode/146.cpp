class LRUCache {
public:
    std::map<int, int> _data;
    std::map<int, int> _weights;
    std::map<int, int> _rank;
    int _w = 0;
    int _capacity = 0;
    LRUCache(int capacity) {
       _capacity = capacity; 
    }
    
    int get(int key) { 
       if (_data.count(key)) {
         auto val = _data[key];
                      
         // update weight
         int old = _weights[key];
         _weights[key] = _w;
         _rank.erase(old);
         _rank[_w] = key;
         _w++;
         return val;
       }
       return -1;
    }
    
    void put(int key, int value) {
        //std::cout << "put:" << key << " " << value << "\n";
        if (_data.count(key)) {
            int old = _weights[key];
            _rank.erase(old);
        } else if (_data.size() == _capacity ) {
            //for (auto& p : _rank) {
                //std::cout << "rank:" << p.first << " " << p.second << "\n";
            //}
            auto weight = _rank.begin()->first;
            auto key = _rank.begin()->second;
            //std::cout << _data.size() << " delete:" << key << " " << _data[key] << " " << weight << std::endl;

            _data.erase(key);
            _weights.erase(key);
            _rank.erase(weight);
        } 
        _data[key] = value;
        _weights[key] = _w;
        _rank[_w] = key;
        ++_w;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
