#include <iostream>
using namespace std;

int main()
{
    int c = 5, no = 10;
    do {
        no /= c;
    } while(c--);

    cout <<  no << endl;
    return 0;
}