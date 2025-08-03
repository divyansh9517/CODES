#include<bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
};

class Solution{
    public:
    static bool comp(meeting d1,meeting d2)
    {
        return d1.end<d2.end;
    }
    int meetingNum(vector<int>& start,vector<int> & end)
    {
        vector<meeting> meet;
        for(int i  = 0 ; i < start.size() ; i++)
        {
            meet.push_back({start[i],end[i]});
        }

        sort(meet.begin(),meet.end(),comp);
        int freeTime = meet[0].end;
        int cnt =1;

        for(int i = 1 ; i < meet.size(); i++)
        {
            if(meet[i].start >= freeTime)
            {
                cnt = cnt+1;
                freeTime = meet[i].end;
            }
        }
        return cnt;

    }
};

int main()
{
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end ={2,4,6,7,9,9};

    Solution s;
    int ans = s.meetingNum(start,end);
    cout<<ans<<" "<<endl;
}