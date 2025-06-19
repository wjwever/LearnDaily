/*************************************************************************
    > File Name: 30.cpp
    > Author: frank
    > Mail: 1216451203@qq.com
    > Created Time: 2025年06月19日 星期四 13时42分34秒
 ************************************************************************/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordNum = words.size();
        int wordSize = words[0].size();
        vector<int> res;

        std::cout << "hello" << wordNum << " " << wordSize << std::endl;
        for (int i = 0; i < wordSize and i + wordSize * wordNum <= s.size(); ++i) {
           int left = i; 
           int right = i + wordSize * wordNum;
           std::map<string, int> wordsMap;
           for (int j = left; j < right; j+=wordSize) {
                wordsMap[s.substr(j, wordSize)] ++;
           }
           for (const string& word: words) {
                wordsMap[word] --;
                if (wordsMap[word] == 0) {
                    wordsMap.erase(word);
                }
           }
           if (wordsMap.empty()) {
                res.push_back(left);
           }
           while (right < s.size()) {
                const string& deleteWord = s.substr(left, wordSize);
                const string& joinWord = s.substr(right, wordSize);
                if (--wordsMap[deleteWord] == 0) {
                    wordsMap.erase(deleteWord);
                }
                if (++wordsMap[joinWord] == 0) {
                    wordsMap.erase(joinWord);
                }
                right += wordSize;
                left += wordSize;
                if (wordsMap.empty()) {
                    res.push_back(left);
                }
           }
        }
        return res;
    }
};
