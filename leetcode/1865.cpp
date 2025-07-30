/*************************************************************************
    > File Name: leetcode/1865.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月13日 星期日 08时48分12秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class FindSumPairs {
public:
    vector<int> _nums1;
    vector<int> _nums2;
    std::map<int, std::map<int, int>> _book; // index -> [sum, cnt]

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        _nums1 = nums1;
        _nums2 = nums2;
        for (int i = 0; i < _nums2.size(); ++i) {
            int n2 = _nums2[i];
            for (auto n1 : _nums1) {
                ++_book[i][n1 + n2];
            }
        }
    }
    
    void add(int index, int val) {
        std::map<int, int> book;
        for (auto &[k, v] : _book[index]) {
            book[k + val] = v;
        }
        _book[index] = book;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto it = _book.begin(); it != _book.end(); ++it) {
            for (auto& [k, v] : it->second) {
                if (tot == k) {
                    res += v;
                }
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */


class FindSumPairs {
public:
    vector<int> _nums1;
    vector<int> _nums2;
    //std::map<int, std::map<int, int>> _book; // index -> [sum, cnt]
    std::unordered_map<int, int> _cnt;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        _nums1 = nums1;
        _nums2 = nums2;
        for (auto& n : _nums2) {
            ++_cnt[n];
        }
    }

    void add(int index, int val) {
        int old = _nums2[index];
        _nums2[index] += val;
        --_cnt[old];
        ++_cnt[old + val];
    }

    int count(int tot) {
        int res = 0;
        for (auto n : _nums1) {
            res += _cnt[tot - n];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
