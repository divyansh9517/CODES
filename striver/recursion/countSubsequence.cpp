// #include<bits/stdc++.h>
// using namespace std;

// int solve(int idx , int target, vector<int> &nums)
// {
//     if(idx == 0){

//         if(target == 0  nums[0] == 0)return 2; //  pick or not piick for zero 

//         if(target == 0 || nums[0]== target){
//             return 1;
//         }
//         return 0;
//     }

//     // pick nhi krengy element ko 
//     int not_pick = solve(idx -1,target,nums);
//     int pick = 0;
//     if(nums[idx] <= target){

//         // pick kr rhy hai element ko 
//         pick = solve(idx -1 , target - nums[idx],nums);
//     }

//     // pick aur not pick  dono ko add kr rhy hai
//     return pick + not_pick;
// }

// int main(){
//     vector<int> arr = {1,4,4,5};
//     int target = 5;
//     int anss = solve(arr.size()-1,target,arr);
//     cout<<anss<<endl;
//     return 0;
// }


// by left recursion and right recursion

#include<bits/stdc++.h>
using namespace std;

int f(int idx , vector<int>& ds,int s , int sum ,vector<int> &arr,int n){
    if(idx == n){
        if(s == sum){
            return 1;
            // for(auto  it : ds)cout<<it<<" ";
        }
        //cout<<endl;
        return 0;
    }
    ds.push_back(arr[idx]);
    s+= arr[idx];
    int l = f(idx+1 , ds,s,sum,arr,n);// pick 

    ds.pop_back();
    s-=arr[idx];
    int r = f(idx+1 , ds,s,sum,arr,n); // not pick
    return l + r;
}

int main(){
    vector<int> arr = {1,2,2,3};
    vector<int>ds;
    cout<<f(0,ds,0,3,arr,arr.size());
    return 0;
}