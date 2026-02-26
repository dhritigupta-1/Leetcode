class Trie {

    struct TrieNode {
        TrieNode* children[26];
        bool eow;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
            eow = false;
        }
    };

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->eow = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return curr->eow;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};