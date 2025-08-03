#include <bits/stdc++.h>
using namespace std;

struct Movie {
    int start, end;
};

bool cmp(Movie &a, Movie &b) {
    return a.end < b.end;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }

    sort(movies.begin(), movies.end(), cmp);

    multiset<int> freeTimes;
    for (int i = 0; i < k; i++) {
        freeTimes.insert(0);
    }

    int count = 0;
    for (auto &movie : movies) {
        auto it = freeTimes.upper_bound(movie.start);
        if (it == freeTimes.begin()) {
            continue;
        }
        it--;
        freeTimes.erase(it);
        freeTimes.insert(movie.end);
        count++;
    }

    cout << count << "\n";

    return 0;
}
