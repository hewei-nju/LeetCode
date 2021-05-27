class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        word_dict = new unordered_set<string>();
    }
    
    void addWord(string word) {
        this->word_dict->insert(word);
    }
    
    bool search(string word) {
        return this->word_dict->count(word) > 0;
    }
private:
    unordered_set<string> *word_dict;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */