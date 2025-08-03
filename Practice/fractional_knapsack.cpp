#include<bits/stdc++.h>
using namespace std;

struct item{
    int val;
    int wt;
};
class Solution{
    public : 

    static bool comp(item v1,item v2)
    {
        double  r1 = (double) v1.val / v1.wt; 
        double r2 = (double) v2.val / v2.wt;

        return r1>r2;
    }
    double solve(vector<int>& value,vector<int> &wt,int capacity)
    {
        vector<item> it;
        for(int i = 0 ; i < wt.size(); i++)
        {
            it.push_back({value[i],wt[i]});
        }

        sort(it.begin(),it.end(),comp);
        double  totalCost;

        for(int i = 0 ; i < it.size() ; i++)
        {
            if(it[i].wt <= capacity)
            {
                totalCost += it[i].val;
                capacity -= it[i].wt;
            }
            else{
                totalCost += it[i].val * ((double)capacity / it[i].wt);
                break;
            }
        }
        return totalCost;
    }
};

int main(){
   vector<int> val = {60,100,120};
   vector<int> wt = {10,20,30};
   
   int capacity = 50;
   Solution s;
   double  ans  = s.solve(val,wt,capacity);
   cout<<ans<<endl;
}
