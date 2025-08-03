#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
static bool comp(Item val1,Item val2)
{
    double r1 = (double)val1.value / val1.weight;
    double r2 = (double)val2.value / val2.weight;
    return r1 > r2;
}
double fractionalKnapsack(vector<int> &val,vector<int> &wt,int capa)
{
    vector<Item> item;
    for (int i = 0; i < val.size(); i++) 
        {
            items.push_back({val[i], wt[i]});
        }

    sort(item.begin(),item.end(),comp);
    int totalVal = 0;

    for(int i = 0 ; i < val.size() ;i++)
    {
        if(item[i].weight <= capa)
        {
            totalVal += item[i].value;
            capa -= item[i].weight;
        }
        else{
            totalVal += item[i].value * ((double)capa/(double)item[i].weight);
        }
    }
    return totalVal;

}