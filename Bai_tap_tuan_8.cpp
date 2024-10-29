#include <bits/stdc++.h>
using namespace std;
struct Node {
    int Bac;     
    int He_so;
    Node* next;      
    Node(int d, int c) : Bac(d), He_so(c), next(nullptr) {}
};
class Polynomial {
private:
    Node* head;
public:
    Polynomial() : head(nullptr) {}
    ~Polynomial() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void addTerm(int Bac, int He_so) {
        if (He_so == 0) return; 
        Node* newNode = new Node(Bac, He_so);
        if (!head || head->Bac < Bac) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->Bac > Bac) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    void print() const {
        if (!head) {
            cout << "0" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->He_so << "x^" << current->Bac;
            if (current->next) cout << " + ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    Polynomial poly;
    int Bac, He_so;
    cout << "Nhap cac phan tu cua da thuc (nhap -1 de ket thuc):\n";
    while (true) {
        cout << "Nhap bac cua phan tu: ";
        cin >> Bac;
        if (Bac == -1) break;
        cout << "Nhap he so cua x^" << Bac << ": ";
        cin >> He_so;
        poly.addTerm(Bac, He_so);
    }
    cout << "Da thuc vua nhap: ";
    poly.print();
    return 0;
}
