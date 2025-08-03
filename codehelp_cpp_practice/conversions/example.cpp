#include <iostream>
using namespace std;

int main() {
    int num = 5; 
    int pos = 1;

   
    int result = num | (1 << pos);

    cout << "Original number: " << num << endl;
    cout << "Number after setting bit at position " << pos << ": " << result << endl;

    return 0;
}