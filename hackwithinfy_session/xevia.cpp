#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<int> seg;

void build(int idx, int low, int high, int level)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, level - 1);
    build(2 * idx + 2, mid + 1, high, level - 1);

    if (level % 2 == 1){
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    }
        
    else{
        seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
        
}
void update(int idx, int low,int high,int i ,int nv ,int level)
{
    if(low == high)
    {
        arr[i] = nv;
        seg[idx] = nv;
        return;
    }
    int mid = (low + high)/2;


    if(i <= mid)
    {
        update(2*idx + 1, low ,mid,i,nv ,level+1);
    }
    else{
        update(2*idx + 2 , mid+1,high,i,nv,level+1);
    }

    if((n- level) %2 == 1) 
        seg[idx] = seg[2*idx + 1]  | seg[2*idx + 2];
    else{
        seg[idx] = seg[2*idx+1] ^ seg[2*idx + 2];
    }
}

int main()
{
    int q;
    cin >> n>>q;
    int te = 1 << n;

    arr.resize(te);
    seg.resize(4 * te);

    for (int i = 0; i < te; ++i)
    {
        cin >> arr[i];
    }
    build(0, 0, te - 1, n);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--;
        update(0, 0, te - 1, a, b, 0);

        cout << seg[0] << endl;
    }

    

    

    return 0;
}
