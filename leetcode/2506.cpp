/*************************************************************************
    > File Name: leetcode/2506.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年07月17日 星期四 12时13分57秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}
class Solution {
public:
    string encode(const string& input) {
        std::set<char> book;
        for (auto& c : input) {
            book.insert(c);
        }
        string res;
        for (auto it = book.begin(); it != book.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    } 

    int similarPairs(vector<string>& words) {
        std::map<string, int> book;   
        for (auto& word : words) {
            ++book[encode(word)];
        }
        int cnt = 0;
        for (auto&[k,v] : book) {
            std::cout << k << "\t" << v << std::endl;
            cnt += v * (v-1) / 2;
        }
        return cnt;
    }
};


class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (const string& word : words) {
            int state = 0;
            for (char c : word) {
                state |= 1 << (c - 'a');
            }
            res += cnt[state];
            cnt[state]++;
        }
        return res;
    }
};

