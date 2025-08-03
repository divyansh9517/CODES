#include<bits/stdc++.h>
using namespace std;

int solveForLow(vector<int> & arr,int target)
{
    int s = 0;
    int r = arr.size()-1;
    int ans = -1;

    while(s <= r)
    {
        int mid = s+(r-s)/2;

        if(arr[mid] <= target)
        {
            ans = mid;
            s = mid+1;
        }

        else if(arr[mid] < target){
            s = mid+1;

        }
        else{
            r = mid -1;
        }
    }
    return ans;
}
int solveForUpper(vector<int> & arr,int target)
{
    int s = 0;
    int r = arr.size()-1;
    int ans = -1;

    while(s <= r)
    {
        int mid = s+(r-s)/2;

        if(arr[mid] >= target)
        {
            ans = mid;
            r = mid-1;
        }

        else if(arr[mid] < target){
            s = mid+1;

        }
        else{
            r = mid -1;
        }
    }
    return ans;
}

vector<int> getfloorandceil(vector<int> & arr , int target)
{
    int i = solveForLow(arr,target);
    int j = solveForUpper(Arr,target);

    if(i == -1  && j == -1)
    {
        return {-1,-1};
    }

    else if((i == -1 && j !=-1)|| (i != -1 &&  j== -1))
    {
        return {i,j};
    }
    return {arr[i],arr[j]};
}

int main(){
    vector<int> arr = {1,2,8,10,10,11};
    int i = solveForLow(arr,5);
    int j = solveForUpper(arr,5);
    cout<< arr[i]<<endl;
    cout<< arr[j];
}