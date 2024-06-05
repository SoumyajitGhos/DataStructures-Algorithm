#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
    void put(char ch) {
        links[ch - 'a'] = new Node();
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void setLinkNull(char ch) {
        links[ch - 'a'] = nullptr;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void increaseEndsWithCnt() {
        cntEndsWith++;
    }

    void increasePrefixCnt() {
        cntPrefix++;
    }

    int endsWithCnt() {
        return cntEndsWith;
    }

    int prefixCnt() {
        return cntPrefix;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    void deleteEnd() {
        cntEndsWith--;
    }

    bool anyTriePresent() {
        bool isPresent = false;
        for (int i = 0; i < 26; i++) {
            isPresent = isPresent || links[i] != nullptr;
        }
        return isPresent;
    }
};

class Trie {
    private:
        Node* root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(string& word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) node->put(word[i]);
                node = node->get(word[i]);
                node->increasePrefixCnt();
            }
            node->increaseEndsWithCnt();
        }

        int countWordsEqualTo(string& word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) return 0;
                node = node->get(word[i]);
            }
            return node->endsWithCnt();
        }

        int countWordsStartingWith(string& word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) node->put(word[i]);
                node = node->get(word[i]);
            }
            return node->prefixCnt();
        }

        // Just Reducing the endsWith count not managing memory properly
        void erase(string& word) {
            Node* node = root;
            for(int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) return;
                node = node->get(word[i]);
                node->reducePrefix();
            }
            node->deleteEnd();
            if(node->anyTriePresent()) {
                delete node;
            }
        }

        // Effectively solving memory usage problem
        void erase(string& word) {
            Node* node = root;
            eraseRecursive(word, 0, node); 
        }

        bool eraseRecursive(string word, int index, Node* node) {
            // Base case
            if(index == word.length()) {
                if(node->endsWithCnt() > 0) {
                    node->deleteEnd();
                    node->reducePrefix();
                    return node->prefixCnt() == 0 && !node->anyTriePresent();
                }
                return false;
            }
            char ch = word[index];
            if(node->containsKey(ch)) {
                Node* nextNode = node->get(ch);
                bool shouldDeleteNextNode = eraseRecursive(word, index + 1, nextNode);

                if(shouldDeleteNextNode) {
                    delete nextNode;
                    node->setLinkNull(ch);
                }
            }
        }
};
