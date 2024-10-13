#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    int Mau[n];
    for (int i = 0; i < n; i++) {
        cin >> Mau[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++ ) {
            if ( Mau[i] < Mau[j] ) swap(Mau[i], Mau[j]);
        }

    }
    for (int i = 0; i < n; i++) {
        cout << Mau[i] << ' ';
    }
}