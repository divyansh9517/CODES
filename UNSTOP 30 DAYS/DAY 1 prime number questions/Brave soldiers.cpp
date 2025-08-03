#include <iostream>
#include<vector>
using namespace std;
int count_brave_soldiers(int n) {
    vector<bool> isPrime(n+1,true);
    vector<int> prime;
    isPrime[0] = isPrime[1]= false;
    for(int i = 2 ; i<= n ;i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            for(int j = i*2 ; j<=n ; j+=i)
            {
                isPrime[j] =false;
            }
        }
    } 
    return prime.size();
}

int main() {
    int n;
    cin >> n;
    int result = count_brave_soldiers(n);
    cout << result << endl;
    return 0;
}