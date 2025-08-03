#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

const int MAXN = 200005;
int block_size;

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        int block_a = l / block_size;
        int block_b = other.l / block_size;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    block_size = static_cast<int>(sqrt(n)) + 1;

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        queries[i] = {a - 1, b - 1, i};  // Convert to 0-based indexing
    }

    sort(queries.begin(), queries.end());

    unordered_map<int, int> freq;
    vector<int> answers(q);
    int curr_l = 0, curr_r = -1;
    int distinct = 0;

    auto add = [&](int val) {
        freq[val]++;
        if (freq[val] == 1)
            distinct++;
    };

    auto remove = [&](int val) {
        freq[val]--;
        if (freq[val] == 0)
            distinct--;
    };

    for (const Query &query : queries) {
        while (curr_r < query.r) add(arr[++curr_r]);
        while (curr_r > query.r) remove(arr[curr_r--]);
        while (curr_l < query.l) remove(arr[curr_l++]);
        while (curr_l > query.l) add(arr[--curr_l]);

        answers[query.idx] = distinct;
    }

    for (int ans : answers)
        cout << ans << "\n";

    return 0;
}
