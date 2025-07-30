/*************************************************************************
    > File Name: leetcode/381.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月09日 星期三 18时15分40秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class RandomizedCollection {
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        _buffer.push_back(val);
        _pos[val].insert(_buffer.size() - 1);
        return _pos[val].size() == 1;
    }

    bool remove(int val) {
        if (_pos[val].size() == 0) {
            return false;
        }
        int buf_len = _buffer.size();
        if(_buffer.back() == val) {
            _pos[val].erase(buf_len - 1);
            _buffer.pop_back();
            return true;
        }
        int val_id = *_pos[val].begin();
        _pos[val].erase(val_id);

        int back_val = _buffer.back();
        _buffer[val_id] = back_val;
        _buffer.pop_back();

        _pos[back_val].erase(buf_len -1) ;
        _pos[back_val].insert(val_id);
        return true;
    }

    int getRandom() {
        return _buffer[rand() % _buffer.size()];
    }
    std::vector<int> _buffer;
    std::unordered_map<int, set<int>> _pos;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
