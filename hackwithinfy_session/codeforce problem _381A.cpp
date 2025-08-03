#include<bits/stdc++.h>
using namespace std;

int main(){

    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i  = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    //third test case failed on this 

    // sort(arr.begin(),arr.end());
    // reverse(arr.begin(),arr.end());

    // int sarrja = 0;
    // int dima = 0;
    // for(int i = 0 ; i < n ; i++)
    // {
    //     if(i &1)
    //     {
    //         dima += arr[i];
    //     }
    //     else{
    //         sarrja += arr[i];   
    //     }
        
    // }
    
    // without sorting
    int leftIdx = 0; 
    int rightIdx = n-1;
    int serrja = 0;
    int dima = 0;
    int chance = 0;

    while(leftIdx <= rightIdx)
    {
        int pick;
        if(arr[leftIdx]>= arr[rightIdx])
        {
            pick = arr[leftIdx];
            leftIdx++;
        }
        else
        {
            pick = arr[rightIdx];
            rightIdx--;
        }

        if(chance % 2 == 0)
        {
            serrja += pick;
        }
        else
        {
            dima += pick;
        }
        chance++;
    }
    cout<<serrja<<" "<<dima<<endl;
    return 0;

}