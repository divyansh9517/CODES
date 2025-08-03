#include<iostream>
using namespace std;

int abso(int);
long abso(long);
double abso(double);

int main(){
    int i = -25,j;
    long l = -100000, m;
    double d = -12.34,e;

    j = abso(i);
    m = abso(l);
    e = abso(d);

    cout<<j << endl<<m<<endl<<e<<endl;
    return 0;
}

int abso(int ii)
{
    return (ii > 0 ? ii : ii*-1);
}

long abso(long ll)
{
    return (ll > 0  ? ll : ll*-1);
}

double abso(double dd)
{
    return (dd > 0 ? dd : dd * -1);
}