#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char c) : data(c), left(NULL), right(NULL) {}
};

unordered_map<char, Node*> tree;

void preorder(Node* root) {
    if (!root) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        if (tree.find(p) == tree.end()) tree[p] = new Node(p);
        if (l != '.') tree[p]->left = (tree[l] = new Node(l));
        if (r != '.') tree[p]->right = (tree[r] = new Node(r));
    }
    preorder(tree['A']); cout << "\n";
    inorder(tree['A']); cout << "\n";
    postorder(tree['A']); cout << "\n";
}