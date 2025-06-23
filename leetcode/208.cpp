class Trie {
public:
    vector<Trie*> _fanout;
    bool _wordEnd;
    Trie() {
        _wordEnd = false;
        _fanout.resize(26, nullptr);
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->_fanout[c - 'a'] == nullptr) {
                node->_fanout[c - 'a'] = new Trie();
            } 
            node = node->_fanout[c-'a'];
        }
        node->_wordEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->_fanout[c - 'a'] == nullptr) {
                return false;
            } 
            node = node->_fanout[c-'a'];
        }
        return node->_wordEnd; 
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->_fanout[c - 'a'] == nullptr) {
                return false;
            } 
            node = node->_fanout[c-'a'];
            std::cout << node << " " << c << std::endl;
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
