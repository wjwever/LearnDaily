class Solution {
public:
    std::stack<std::pair<std::string, int>> stk;
    string decodeString(string s) {
        string tmpStr = "";
        int val = 0;
        for (auto c : s) {
            std::cout << c << std::endl;
            if (c >= '0' and c <= '9') {
                val = val * 10 + c - '0';
                std::cout << "\t" << " " << val << " " << tmpStr << std::endl;
            } else if (c >= 'a' and c <= 'z') {
                tmpStr.push_back(c);
                std::cout << "\t" << " " << val << " " << tmpStr << std::endl;
            } else if (c == '[') {
                stk.push(std::make_pair(tmpStr, val));
                tmpStr = "";
                val = 0;
                std::cout << "\t" << " " << val << " " << tmpStr << std::endl;
            } else {
                auto p = stk.top(); 
                stk.pop();
                for (int i = 0; i < p.second; ++i) {
                    p.first += tmpStr;    
                }
                val = 0;
                tmpStr = p.first;
                std::cout << "\t" << " " << val << " " << tmpStr << std::endl;
            }
        } 
        return tmpStr;
    }
};
