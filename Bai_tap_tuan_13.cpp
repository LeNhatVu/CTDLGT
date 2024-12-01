#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Customer {
    string name;
    int Tong_so_tien; 
    int So_san_pham_A; 
};
int main() {
    queue<Customer> supermarketQueue; 
    int Tien_thu = 0; 
    int So_san_pham_A_da_ban = 0; 
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Customer c;
        cout << "Nhap ten khach hang: ";
        cin >> c.name;
        cout << "Nhap tong so tien khach hang thanh toan: ";
        cin >> c.Tong_so_tien;
        cout << "Nhap so luong san pham A khach hang mua: ";
        cin >> c.So_san_pham_A;
        supermarketQueue.push(c); 
    }
    while (!supermarketQueue.empty()) {
        Customer currentCustomer = supermarketQueue.front(); 
        supermarketQueue.pop();
        Tien_thu += currentCustomer.Tong_so_tien;
        So_san_pham_A_da_ban += currentCustomer.So_san_pham_A;
        cout << "Khach hang " << currentCustomer.name << " da thanh toan xong." << endl;
    }
    cout << "Tong so tien thu ngan nhan duoc: " << Tien_thu << endl;
    cout << "Tong so luong san pham A da ban: " << So_san_pham_A_da_ban << endl;
    return 0;
}
