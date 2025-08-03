#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> generatePrime(int limit)
{
    vector<bool> isPrime (limit+1,true);
    vector<int> prime;

    isPrime[0]=isPrime[1] = false;

    for(int i = 2 ; i <= limit ; i++)
    {
        if(isPrime[i] == true)
        {
            prime.push_back(i);
            for(int j = i * 2 ; j <= limit ; j+=i)
            {
                isPrime[j] = false;
            }
        }
    
    }
    return prime;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */      
    int n ;
    cin>>n;

    int limit = 1000000;
    vector<int> prime= generatePrime(limit);
    cout<<(prime[n-1] * prime[n-1]) <<endl;
    return 0;
}