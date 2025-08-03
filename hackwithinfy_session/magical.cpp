#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> specTree[N], partTree[N];
int inSpec[N], outSpec[N], timerSpec = 0;
int inPart[N], outPart[N], timerPart = 0;

void dfs(int node, vector<int> tree[], int in[], int out[], int &timer) {
    in[node] = ++timer;
    for (int child : tree[node]) {
        dfs(child, tree, in, out, timer);
    }
    out[node] = ++timer;
}

bool isAncestor(int u, int v, int in[], int out[]) {
    return in[u] < in[v] && out[v] < out[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n + 1), type(n + 1);

    for (int i = 1; i <= n; ++i) {
        int p, t;
        cin >> p >> t;
        parent[i] = p;
        type[i] = t;

        if (p == -1) continue;
        if (t == 0) specTree[p].push_back(i);
        else partTree[p].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (parent[i] != -1 && type[i] == 1) {
            int p = parent[i];
            for (int scChild : specTree[p]) {
                partTree[scChild].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (parent[i] == -1) {
            dfs(i, specTree, inSpec, outSpec, timerSpec);
            dfs(i, partTree, inPart, outPart, timerPart);
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int queryType, u, v;
        cin >> queryType >> u >> v;

        if (queryType == 1) {
            cout << (isAncestor(u, v, inSpec, outSpec) ? "YES" : "NO") << '\n';
        } else {
            cout << (isAncestor(u, v, inPart, outPart) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
