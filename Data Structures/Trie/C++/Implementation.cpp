#include <bits/stdc++.h>
#include<iostream>
using namespace std;

/* Here we are considering that all the words inserted in the Trie is of small case*/
struct Node {
    private:
        Node* links[26];
        bool endsWith = false; // Depict if there is any word ending with it

    public:
        void put(char ch) {
            links[ch - 'a'] = new Node();
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;
        }

        void setEndWith() {
            endsWith = true;
        }

        bool isEnd() {
            return endsWith;
        }
};

/* Implementing the Trie class and its functionality*/
class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node = root;
            for (int i = 0; i < word.length(); i++) {
                if(!node->containsKey(word[i])) node->put(word[i]);
                node = node->get(word[i]);
            }
            node->setEndWith();
        }

        bool search(string word) {
            Node* node = root;
            for (int i = 0; i <= word.length(); i++) {
                if(!node->containsKey(word[i])) return false;
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

        bool startsWith(string prefix) {
            Node* node = root;
            for (int i = 0; i<= prefix.length(); i++) {
                if(!node->containsKey(prefix[i])) return false;
                node = node->get(prefix[i]);
            }
            return true;
            /* The program execution comes out of the loop when the prefix's length expires that means 
                there might be any any word starting with the prerticular prefix so returning "True"
            */
        }
};

int main() {
    Trie* t = new Trie();
    
    t->insert("codoholic");
    t->insert("algorithms");
    cout<<"Is coders is present : "<< t->search("coders");
    cout<<"Is there any word starting with 'cod' : "<< t->startsWith("cod");

    delete t;
    return 0;
}