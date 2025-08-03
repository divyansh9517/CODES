
#include <iostream>
using namespace std;
void crazy(int n, int a, int b)
{
 if (n <= 0)
 return;
 crazy(n - 1, a, b + n);
 cout << n << " " << a << " " << b << endl;
 crazy(n - 1, b, a + n);
}
int main()
{
 crazy(3, 4, 5);
 return 0;
}
