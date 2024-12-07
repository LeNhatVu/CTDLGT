#include <bits/stdc++.h>
using namespace std;
struct Node {
    string value;
    Node* left;  
    Node* right; 
    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};
bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
}
Node* Tao_cay(string postfix[], int size) {
    stack<Node*> st;
    for (int i = 0; i < size; ++i) {
        string token = postfix[i];
        if (!isOperator(token)) { 
            st.push(new Node(token));
        } else { 
            Node* node = new Node(token);
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            st.push(node);
        }
    }
    return st.top();
}
void Trung_to(Node* root) {
    if (root) {
        if (isOperator(root->value)) cout << "(";
        Trung_to(root->left);
        cout << root->value << " ";
        Trung_to(root->right);
        if (isOperator(root->value)) cout << ")";
    }
}
void Tien_to(Node* root) {
    if (root) {
        cout << root->value << " ";
        Tien_to(root->left);
        Tien_to(root->right);
    }
}
void Hau_to(Node* root) {
    if (root) {
        Hau_to(root->left);
        Hau_to(root->right);
        cout << root->value << " ";
    }
}
int main() {
    string postfix[] = {"a", "5", "*", "b", "c", "6", "^", "*", "d", "/", "-", "h", "j", "-", "e", "1", "2", "/", "^", "*", "+"};
    int size = sizeof(postfix) / sizeof(postfix[0]);
    Node* root = Tao_cay(postfix, size);
    cout << "Trung to: ";
    Trung_to(root);
    cout << endl;
    cout << "Tien to: ";
    Tien_to(root);
    cout << endl;
    cout << "Hau to: ";
    Hau_to(root);
    cout << endl;
    return 0;
}
