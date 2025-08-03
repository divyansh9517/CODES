#include<iostream>
using namespace std;
int main()
{
    // int budget ;
    // cin>>budget;

    // if(budget > 2000000)
    // {
    //     cout<<"Yes, you can buy Scorpio";
    // }
    // else{
        
    //     cout<<"Sorry, you cannot buy Scorpio";
    // }


    
    //if - else 

    // int marks = 95;
    // if(marks > 90)
    // {
    //     cout<<"A";
    // }
    // else if(marks > 80)
    // {
    //     cout<<"B";
    // }
    // else if(marks > 70)
    // {
    //     cout<<"C";
    // }
    // else if(marks > 60)
    // {
    //     cout<<"D";
    // }


    //if - else if-else

    // int marks = 85;
    // if(marks > 90)
    // {
    //     cout<<"A";
    // }
    // else if(marks > 80)
    // {
    //     cout<<"B";
    // }
    // else if(marks > 70)
    // {
    //     cout<<"C";
    // }
    // else if(marks > 60)
    // {
    //     cout<<"D";
    // }
    // else{
    //     cout<<"You Failed";
    // }

    //Nested-if

    int height;
    cout<<"Enter height : - "<<endl;
    cin>>height;

    int weight;
    cout<<"Enter your weight : - "<<endl;
    cin>>weight;

    if(height > 5)
    {
        if(weight > 70)
        {
            cout<<"You got a good BMI"<<endl;
        }
        else{
            cout<<"Radhey Radhey"<<endl;
        }
    }
    else{
        cout<<"Radhey Krishna"<<endl;
    }
    return 0;
}