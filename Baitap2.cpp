#include <bits/stdc++.h>
using namespace std;
bool KT (int n) {
    for (int i = 2; i < n; i++ ) if (n % i == 0) return false;
    return true;
}
void sapxep(vector<int> & sx) {
    for (int i = 1; i < sx.size(); i++) {
        for (int j = 0; j < i; j++ ) {
            if ( sx[i] < sx[j] ) swap(sx[i], sx[j]);
        }

    }
}
bool timkiem(vector<int> tk, int tag, int idx) {
    for (int i = idx; i < tk.size(); i++) if (tk[i] == tag) return true;
    return false;
}
int main () {
    cout << "Nhập số n: ";
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 2; i < sqrt(n); i++) {
        if (KT(i)) v.push_back(i);
    }
    vector<int> Vx;
    for (int i = 0; i  < v.size(); i++) {
        for (int j = 0; j <= i; j++) {
            Vx.push_back(v[i] * v[j]);
        }
    }
    sapxep(Vx);
    cout << "Dãy số Blum nhỏ hơn n:\n";
    for ( int i : Vx) cout << i << ' ';
    cout << "\nCặp số có tổng tồn tại trong dãy số: \n";
    for (int i = 0; i < Vx.size()-2; i++) {
        for (int j = i; j < Vx.size()-1; j++) {
            if (timkiem(Vx, Vx[i] + Vx[j], j+1)) cout << Vx[i] << ' ' << Vx[j] << endl;
        }
    }
    while (true) {
        cout << "Nhập số cần tìm: ";
        int tx; cin >> tx;
        if (tx == -1) {cout << "Kết thúc!"; break;}
        if (timkiem(Vx, tx, 0)) cout << "Số cần tim có tồn tại\n";
        else cout << "Số cần tìm không tồn tại\n";
    }
}