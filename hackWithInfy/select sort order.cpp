#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool isPossible(vector<int>& a) {
    map<int, int> freq;
    set<int> elements;

    for (int num : a) {
        freq[num]++;
        if (freq[num] > 2) return false; 
        elements.insert(num);
    }

    for (auto& [val, count] : freq) {
        if (count == 2) {
            
            if (elements.count(val + 1)) {
                return false; /
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        if (isPossible(a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
