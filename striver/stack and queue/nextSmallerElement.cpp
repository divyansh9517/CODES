#include<bits/stdc++.h>
using namespace std;

void nextSmallerElement(vector<int> & nums,int n)
{
    vector<int> arr(n);
    stack<int> st;

    for(int i = 0 ; i < n ; i++)
    {
        while(!st.empty() && st.top() >= nums[i])
        {
            st.pop();
        }
        arr[i] = st.empty()? -1 : st.top();
        st.push(nums[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr= {1,4,5,3,2,6,7,0};
    int n = arr.size();

    nextSmallerElement(arr,n);
    return 0;
}