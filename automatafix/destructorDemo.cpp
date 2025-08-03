#include<iostream>
using namespace std;

class example{
    private :
    int data;

    public :
    example(){
        cout<<"This is a constructor"<<endl;
    }
    ~example()
    {
        cout<<"This is a destructor"<<endl;
    }
};
int main(){
    example e;
    return 0;
}