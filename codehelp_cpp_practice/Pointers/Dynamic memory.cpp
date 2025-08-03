#include<iostream>
using namespace std;

int main(){
//     int *ptr = new int; //  dynamic memory by new keyword
//     *ptr = 5;
//     cout<<*ptr;
//     delete ptr; //  memory free
//     return 0;
// }

    // int *ptr = new int[5];
    // *(ptr+0) = 0;
    // ptr[1] = 1;
    // ptr[2] = 2;
    // ptr[3] = 3;
    // ptr[4] = 4;
    // for(int i = 0 ; i< 5 ; i++)
    // {
    //     cout<<ptr[i];
    // }
    // cout<<endl;

    // cout<<*(ptr+1);

    
    int a = 5;
    int *ptr = &a;
    cout<<sizeof(ptr);
    // int  **ctr= &ptr;
    // int ***dtr = &ctr;

    // cout<<a<<endl;
    // cout<<&a<<endl;
    // cout<<ptr<<endl;
    // cout<<&ptr<<endl;
    // cout<<*ptr<<endl;
    // cout<<ctr<<endl;
    // cout<<&ctr<<endl;
    // cout<<*ctr<<endl;
    // cout<<**ctr<<endl;
    // cout<<dtr<<endl;
    // cout<<&dtr<<endl;
    // cout<<*dtr<<endl;
    // cout<<**dtr<<endl;
    // cout<<***dtr<<endl;

    // int a[] = {1,2,3,4,5,6};
    // cout<<a<<endl;
    // cout<< a +1<<endl;
    // cout<< &a +1<<endl;
    // cout<< *&a +1<<endl;
    // cout<< &a<<endl;
}