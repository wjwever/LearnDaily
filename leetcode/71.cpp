class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);	// 输入流
        string token;			// 接收缓冲区
        deque<string> sk;
        while (getline(iss, token, '/'))	// 以split为分隔符
        {
            cout << token << endl; // 输出
            #if 1
            if (token.empty()) {
                
            }  else if (token == ".") {
                continue;
            }
            else if (token == "..") {
                if (sk.size() > 0) {
                    sk.pop_back();
                }
            } else {
                sk.push_back(token);
            }
            #endif
        }
        std::string res = "";
        for (int i = 0; i < sk.size(); ++i) {
            res += "/";
            res += sk[i];
        }
        return res.empty() ? "/" : res;
    }
};
