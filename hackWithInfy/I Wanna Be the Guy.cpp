#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int p;
    cin >> p;
    vector<int> littleX(p);
    for (int i = 0; i < p; i++) {
        cin >> littleX[i];
    }

    int q;
    cin >> q;
    vector<int> littleY(q);
    for (int i = 0; i < q; i++) {
        cin >> littleY[i];
    }

    set<int> level;

    for (int i = 0; i < p; i++) {
        level.insert(littleX[i]);
    }

    for (int i = 0; i < q; i++) {
        level.insert(littleY[i]);
    }

    if (level.size() == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}
