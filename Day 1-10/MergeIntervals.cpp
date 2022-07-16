#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void helper(stack<pair<int,int>>qpair,vector<vector<int>> &vec)
    {
        while(!qpair.empty())
        {
            pair<int,int>d=qpair.top();
            vec.push_back({d.first,d.second});
            qpair.pop();
        }
    }
    void printPair(pair<int, int> p)
    {

        cout << "("
             << p.first << ", "
             << p.second << ") ";
    }

    // Print the Stack of Pairs
    void Showstack(stack<pair<int, int> > s)
    {
        while (!s.empty()) {
            printPair(s.top());
            s.pop();
        }

        cout << '\n';
    }
  
   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>>qu;
        sort(intervals.begin(),intervals.end());
        pair<int,int>d={intervals[0][0],intervals[0][1]};
        qu.push(d);
        vector<vector<int>> vec;
        // vec=intervals;
        // vec.push_back(intervals[0]);
        // cout<<vec[0][0]<<vec[0][1];
        // vec.pop_back();
        for(int i=1;i<intervals.size();i++)
        {
            
            pair<int,int>f=qu.top();
            if(intervals[i][0]<=f.second)
            {
                if(intervals[i][1]<=f.second)
                {
                    continue;
                }
                qu.pop();
                pair<int,int>pr={f.first,intervals[i][1]};
                qu.push(pr);

            }
            else
            {
                pair<int,int>pr={intervals[i][0],intervals[i][1]};
                qu.push(pr);
            }
        }
        Showstack(qu);
        helper(qu,vec);
        sort(vec.begin(),vec.end());
        return vec;
        
        
    }
};

int main()
{
    
    return 0;
}