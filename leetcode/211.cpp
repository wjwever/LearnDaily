class Trie {
public:
    Trie() {
        _nodes.resize(27, nullptr);
    }
    vector<Trie*> _nodes;
    bool wordEnd = false;
};

class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
       root = new Trie(); 
    }
    
    void addWord(string word) {
        auto pt = root;
        for (char c:word) {
            if (pt->_nodes[c-'a'] == nullptr) {
                pt->_nodes[c-'a'] = new Trie();
            }
            pt = pt->_nodes[c-'a'];
        }
        pt->wordEnd = true;
    }
    bool search(string word) {
        return search(root, word, 0);
    }

    bool search(Trie* node, std::string& word, int step) {
        //std::cout << "search:" << node << " " <<  word << " " << step << "\n";
        if (!node) {
            //std::cout << "ret false\n";
            return false;
        }
        if (step == word.size()) {
            //std::cout << "ret " << node->wordEnd << "\n";
            return node->wordEnd;
        }
        char c = word[step];
        //std::cout << c << "\n";
        if (c=='.') {
            for (auto node : node->_nodes) {
                if (node and search(node, word, step + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return search(node->_nodes[c-'a'], word, step + 1);
        }
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
