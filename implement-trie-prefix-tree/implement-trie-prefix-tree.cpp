class Node{
    public:
    unordered_map<char,Node*> M;
    bool terminal;
    char value;
    Node(char c){
        this->terminal = false;
        this->value = c;
    }
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->M.count(word[i])){
                temp = temp->M[word[i]];
            }
            else{
                temp->M[word[i]] = new Node(word[i]);
                temp = temp->M[word[i]];
            }
        }
        temp->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->M.count(word[i])){
                temp = temp->M[word[i]];
            }
            else{
                return false;
            }
        }
        return temp->terminal;   
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(temp->M.count(word[i])){
                temp = temp->M[word[i]];
            }
            else{
                return false;
            }
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