#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> gia;
    gia.insert(make_pair("A", 1000));
    gia.insert(make_pair("B", 2000));
    gia.insert(make_pair("C", 3000));
    gia.insert(make_pair("D", 5000));

    cout << "Bang gia san pham\n";
    cout << "Ten san pham\tGia\n";
    for (auto i : gia) cout << i.first << "\t\t" << i.second << endl;

    queue<map<string, int>> thanhtoan;
    int kh; cout << "Nhap so luong khach hang: ";
    cin >> kh; 
    for (int i = 0; i < kh; i++) {
        cout << "Khach hang " << i+1 << endl;
        cout << "Nhap so loai san pham: ";
        int n; cin >> n;
        map<string, int> mp; 
        cout << "Nhap ten san pham va so luong can mua:\n";
        for (int i = 0; i < n; i++) {
            string a; int x; cin.ignore(); cin >> a >> x;
            mp[a] = x;
        }
        thanhtoan.push(mp);
    }

    int tongtien = 0, soluongA = 0;
    while (!thanhtoan.empty()){
        map<string, int> mp = thanhtoan.front(); thanhtoan.pop();
        for (auto i : mp) tongtien += (i.second * gia[i.first]);
        if (mp.find("A") != mp.end()) soluongA += mp["A"];
    }

    cout << "Tong tien thu duoc trong phien lam viec: " << tongtien << endl;
    cout << "So luong san pham A da duoc ban: " << soluongA << endl;
}
