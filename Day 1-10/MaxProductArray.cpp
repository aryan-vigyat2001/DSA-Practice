#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int MIN=ans;
        int MAX=ans;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(MIN,MAX);
            }
            MIN=min(nums[i],nums[i]*MIN);
            MAX=max(nums[i],nums[i]*MAX);
            ans=max(ans,MAX);
        }
        return ans;
        
    }
};


int main()
{
    
    return 0;
}