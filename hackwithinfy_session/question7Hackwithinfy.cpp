#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union ke liye parent aur rank arrays
vector<int> parent, rankArr;

// Har component ke liye ek set of nodes aur uski beauty store karne ke liye maps
map<int, set<int>> componentMap;
map<int, int> componentBeauty;

// Find function (DSU) - path compression ke saath
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // parent update ho jaata hai directly root se
}

// Union function (DSU) - rank ke basis pe merge karta hai, aur new root return karta hai
int unionn(int x, int y) {
    if (rankArr[x] < rankArr[y]) {
        parent[x] = y;
        return y;
    } else if (rankArr[x] > rankArr[y]) {
        parent[y] = x;
        return x;
    } else {
        parent[x] = y;
        rankArr[y]++;
        return y;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize parent and rank arrays
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);

    // Har node ko ek naya component bana dete hain initially
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        set<int> s;
        s.insert(i); // har component mein sirf ek node initially
        componentMap[i] = s;
        componentBeauty[i] = 1; // har node ki beauty 1 (1 segment)
    }

    int totalBeauty = 0; // final answer ke liye

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            // type 1: dono nodes ko ek component mein merge karo
            int ru = find(u);
            int rv = find(v);

            if (ru != rv) {
                int newRoot = unionn(ru, rv); // union kar diya
                int oldRoot = (newRoot == ru) ? rv : ru;

                // dono components ke sets aur beauty values
                set<int>& setNew = componentMap[newRoot];
                set<int>& setOld = componentMap[oldRoot];
                int beauty = componentBeauty[newRoot];

                // old component ke har node ko new mein add karne se beauty update karni padegi
                for (int node : setOld) {
                    bool hasLeft = setNew.count(node - 1); // left neighbor present?
                    bool hasRight = setNew.count(node + 1); // right neighbor present?

                    if (hasLeft && hasRight) {
                        beauty--; // dono side already present, 2 segments merge ho gaye
                    } else if (!hasLeft && !hasRight) {
                        beauty++; // new segment create ho gaya
                    }
                    // warna ek taraf se connect hai to koi change nahi
                    setNew.insert(node); // node ko naye set mein daal do
                }

                // map updates
                componentMap[newRoot] = setNew;
                componentMap.erase(oldRoot); // old component hat gaya
                componentBeauty[newRoot] = beauty;
                componentBeauty.erase(oldRoot);
            }

        } else if (type == 2) {
            // type 2: current component ki beauty total mein add karo
            int root = find(u);
            totalBeauty += componentBeauty[root];
        }
    }

    // final beauty print karo
    cout << totalBeauty << endl;
    return 0;
}
