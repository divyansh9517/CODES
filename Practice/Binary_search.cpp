#include<bits/stdc++.h>

using namespace std;

int solveBinary(vector<int> arr,int left ,int right,int target)
{
    while(left < right){
        int mid = left +(right - left)/2;
        if(arr[mid] == target)
        {
            return mid;
        }

        if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int left = 0 ;
    int right = arr.size();
    cout<<solveBinary(arr,left,right,6);
}