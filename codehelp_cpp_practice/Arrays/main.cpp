#include<iostream>
using namespace std;


int sumOfElement(int arr[],int size)
{
    int sum = 0 ;
    for(int i = 0 ; i < size ;i++)
    {
        sum += arr[i];
        //cout<<"Sum for index "<<i<< " - "<<sum<<" "<<endl;
    }

    return sum;

}
void flipGame(int arr[],int size)
{
    for(int i =0 ; i < size;i++)
    {
        if(arr[i] == 0)
        {
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
}
void printa(int arr[],int size)
{
    for(int i =0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// at the time of function in which we take parametere as 2d array we have to put the value of column like that i have done here

void print2dArray(int arr[][3],int row,int col)
{
    for(int i = 0; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }   
}
int main(){


    // Array -> array is a data structure used to store same type of element in a single variable 

    // in this continous allocate memory  
    //declaration
    // int laxman[101];
   

    // we can access element in from the array by the help og index

    // starting iindex of array is 0 and ending index of array is n-1

    //declaration and definition
    // int brr[5] = {10,20,30,40,50};

    // int crr[] = {10,20,30,40,50};
    // cout<<"brr ka size : - "<<brr<<" "<<"Crr ka size :-  "<<crr<<endl;

    // int table[10] ={2,4,6,8,10,12,14,16,18,20};
    // traversing of array

    // for(int i = 0 ; i < 10 ;i++)
    // {
    //     cout<<table[i]<<" ";
    // }
    // cout<<endl;
    // cin>>table[9];
    // for(int i = 0; i< 10 ; i++)
    // {
    //     cout<<table[i]<<" ";
    // }


    // taking input in array

    // int arr[5];
    // in this insertion you have to input an numbers from 1 to 10

    // for(int i = 0 ; i < 5 ; i++)
    // {
    //     cin>>arr[i];
    // }

    // int ans = sumOfElement(arr,5);
    // cout<<ans;

    // int n ;
    // cout<< "entere a number to which you want to print table  : - ";

    // cin>>n;

    // for(int i = 0 ; i < 10 ; i++)
    // {
    //     int ans = arr[i]*n;
    //     cout<<ans<<" "<<endl;
    // }

    // int sum = 0;

    // for(int i = 0 ; i < 10 ;i++)
    // {
    //     sum += arr[i];
    //     cout<<"Sum for index "<<i<< " - "<<sum<<" "<<endl;
    // }
    // cout<<"Sum of element in array is : - "<<sum<<endl;

    // int arr[5] = {1,0,1,0,1} ;
    // printa(arr,5);
    // flipGame(arr,5);
    // printa(arr,5);







    // 2d  array

   // int arr[3][3]; // declaration of 2d 

    int brr[3][3] = {
        {1,2,3},{1,2,3},{1,2,3}
        }; // defintion or intialization

    int row = 3;
    int col = 3;
    print2dArray(brr,row,col);

    // for(int i = 0; i < row ; i++)
    // {
    //     for(int j = 0 ; j < col ; j++)
    //     {
    //         cout<<brr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // accessing element present at  2,1
    //cout<<brr[2][1];

    return 0;  

}