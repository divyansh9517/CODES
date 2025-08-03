#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
}

double fractionalKnapsac(int w , Item arr[],int n)
{
    vector<pair<double,Item>> v;
    for(int i = 0 ; i < n ;i++)
    {
        double perunit = (1.0*arr[i].value)/arr[i].weight;
        pair<double,Item> p =  make_pair(perunit,arr[i]);
        v.push_back(p);
    }
    sort(v.being(),v.end(),comp);
    double totalVal = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(v[i].second.weight > w)
        {
            totalVal = w*v[i].first;
            w = 0;
        }
        else{
            totalVal += v[i].second.value;
            w = w-v[i].second.weight;

        }
    }
    return totalVal;
}