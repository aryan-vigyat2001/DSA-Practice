#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>vec;
        int n=nums.size();
        if(n<3)
        return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                 continue;
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    vec.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;
                    while(l<r && nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }
                else
                    if(nums[i]+nums[l]+nums[r]<0)
                    {
                        l++;
                    }
                else
                {
                    r--;
                }
            }
                                
        }
        return vec;
            
    }
};

int main()
{
    
    return 0;
}