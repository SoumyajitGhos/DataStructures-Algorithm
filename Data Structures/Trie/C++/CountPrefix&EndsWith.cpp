#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    void put(char ch) {
        links[ch - 'a'] = new Node();
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
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
            isPresent = isPresent || links[i] != NULL;
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

        void insert(string word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) node->put(word[i]);
                node = node->get(word[i]);
                node->increasePrefixCnt();
            }
            node->increaseEndsWithCnt();
        }

        int countWordsEqualTo(string word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) return 0;
                node = node->get(word[i]);
            }
            return node->endsWithCnt();
        }

        int countWordsStartingWith(string word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) node->put(word[i]);
                node = node->get(word[i]);
            }
            return node->prefixCnt();
        }

        void erase(string word) {
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
};
