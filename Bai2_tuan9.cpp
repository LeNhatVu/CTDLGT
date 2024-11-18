#include <bits/stdc++.h>
using namespace std;
struct Node {
    string word;   
    int count;     
    Node* next;    
};

Node* createNode(string word) {
    Node* newNode = new Node();
    newNode->word = word;
    newNode->count = 1;
    newNode->next = nullptr;
    return newNode;
}
void addWord(Node*& head, string word) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->word == word) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = createNode(word);
    newNode->next = head;
    head = newNode;
}
string findMostFrequent(Node* head) {
    string mostFrequent;
    int maxCount = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->count > maxCount) {
            maxCount = temp->count;
            mostFrequent = temp->word;
        }
        temp = temp->next;
    }
    return mostFrequent;
}
void removeDuplicateWords(Node*& head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->word == current->next->word) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}
int countUniqueWords(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->word << " (" << temp->count << ")" << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;
    string sentence;
    cout << "Nhap cau Tieng Viet: ";
    getline(cin, sentence);
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        addWord(head, word);
    }
    cout << "Danh sach tu va so lan xuat hien:\n";
    printList(head);
    cout << "Tu xuat hien nhieu nhat: " << findMostFrequent(head) << endl;
    removeDuplicateWords(head);
    cout << "Danh sach tu sau khi bo tu lap:\n";
    printList(head);
    cout << "So tu duy nhat trong cau: " << countUniqueWords(head) << endl;
    return 0;
}
