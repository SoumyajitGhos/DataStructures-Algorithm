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

    void updateEndsWithCnt() {
        cntEndsWith++;
    }

    void updatePrefixCnt() {
        cntPrefix++;
    }
};
