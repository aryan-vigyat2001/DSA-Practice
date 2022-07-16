#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>vec;
        sort(nums.begin(),nums.end());
        // vec.push_back(nums);
        int n=nums.size();
        if(n<4)
        {
            return {};
        }
        // vec.push_back(nums);
        for(int i=0;i<nums.size()-3;i++)
        {
            // if(i>0 && nums[i]==nums[i-1])
            // {
            //     continue;
            // }
            for(int j=i+1;j<nums.size()-2;j++)
            {
                // if(j>0 && nums[j]==nums[j-1])
                // {
                //     continue;
                // }
                int l=j+1;
                int r=nums.size()-1;
                // cout<<nums[i]<<" - "<<nums[j]<<" - "<<nums[l]<<" - "<<nums[r]<<endl;
                while(l<r)
                {
                    if(long(nums[i])+long(nums[j])+long(nums[l])+long(nums[r])==target)
                {
                    vec.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;
                    while(l<r && nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }
                else
                    if(long(nums[i])+long(nums[j])+long(nums[l])+long(nums[r])<target)
                    {
                        l++;
                    }
                else
                {
                    r--;
                }
                    
                }
                while(j+1<n && nums[j]==nums[j+1])  j++;
                
            }
            while(i+1<n && nums[i]==nums[i+1])  i++;
        
        }
        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        return vec;
    }
};

int main()
{
    
    return 0;
}