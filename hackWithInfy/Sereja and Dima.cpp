#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ;i++)
    {
        cin>>arr[i];
    }
    int left=0;
    int right = n -1;
    int sereja = 0,dima = 0;
    int turn = 0;
    while(left <= right)
    {
        int choose;
        if(arr[left] >= arr[right])
        {
            choose = arr[left];
            left++;
        }
        else{
            choose = arr[right];
            right--;
        }

        if(turn % 2 == 0)
        {
            sereja += choose;
        }
        else{
            dima+= choose;
        }
        turn++;
    }
    cout<<sereja<<" "<<dima<<endl;
    return 0;
}