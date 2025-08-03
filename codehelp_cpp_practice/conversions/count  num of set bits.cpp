#include <iostream>
using namespace std;

int countSetBits(int num) {
    // int count = 0;
    // while (num) count++, num &= (num - 1);
    // return count;
    return __builtin_popcount(num);
}

int main() {
    int num = 29; 

    cout << "Number of set bits in " << num << " is: " << countSetBits(num) << endl;

    return 0;
}