#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& arr) {
    int n = a.size();
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    } 

    if (sum > n - 1 || (sum == 0 && n > 1))
    {
        return true;
    } 
    for (int i = 0; i < n - 1; ++i) 
    {
        if (arr[i] == 0 && arr[i + 1] == 0)
        {
            return true;
        }
            
    }

    return false;
}

int main() {
    int test_case;
    cin >> test_case;

    while (test_case--) 
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        if (solve(arr)) 
        {
            cout << "YES\n";
        } 
        else 
        {
            cout << "NO\n";
        }
    }

    return 0;
}