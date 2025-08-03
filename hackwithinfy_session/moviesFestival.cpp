#include <bits/stdc++.h>
using namespace std;

struct Movie {
    int start, end;
};

bool compare(Movie a, Movie b) {
    return a.end < b.end;  
}

int main() {
    int n;
    cin >> n;
    vector<Movie> movies(n);
    
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }

    
    sort(movies.begin(), movies.end(), compare);

    int cnt = 0;
    int last_end_time = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i].start >= last_end_time) {
            cnt++;
            last_end_time = movies[i].end;
        }
    }

    cout << cnt << endl;
    return 0;
}
