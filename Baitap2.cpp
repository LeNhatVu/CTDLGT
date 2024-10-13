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
int main () {
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
    for ( int i : Vx) cout << i << ' ';
}