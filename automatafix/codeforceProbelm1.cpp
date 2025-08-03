#include <bits/stdc++.h>
using namespace std;

int n, m, nm;
vector<int> basePattern;

int query(int ring, int dir) {
    cout << "? " << ring << " " << dir << endl;
    cout.flush();
    int val;
    cin >> val;
    return val;
}

int main() {
    cin >> n >> m;
    nm = n * m;

    basePattern.resize(nm);
    
    // Rotate ring 0 nm times and store display values
    for (int i = 0; i < nm; ++i) {
        basePattern[i] = query(0, 1);
    }

    // Restore ring 0 to original position
    for (int i = 0; i < nm; ++i)
        query(0, -1);

    vector<int> result(n - 1, -1);

    for (int ring = 1; ring < n; ++ring) {
        vector<int> curPattern(nm);
        for (int i = 0; i < nm; ++i) {
            curPattern[i] = query(ring, 1);
        }

        // Restore this ring back to original
        for (int i = 0; i < nm; ++i)
            query(ring, -1);

        // Find rotation offset where patterns match
        for (int shift = 0; shift < nm; ++shift) {
            bool match = true;
            for (int i = 0; i < nm; ++i) {
                if (curPattern[i] != basePattern[(i + shift) % nm]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result[ring - 1] = shift;
                break;
            }
        }
    }

    // Output result
    cout << "! ";
    for (int x : result) cout << x << " ";
    cout << endl;
    cout.flush();

    return 0;
}
