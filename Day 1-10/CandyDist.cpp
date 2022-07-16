#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>leftarr(n,1);
        vector<int>rightarr(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                leftarr[i]=leftarr[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                rightarr[i]=rightarr[i+1]+1;
            }
        }
        int totalcandy=0;
        for(int i=0;i<n;i++)
        {
            int mx=max(leftarr[i],rightarr[i]);
            totalcandy+=mx;
        }
        return totalcandy;
    }
};

int main()
{
    
    return 0;
}