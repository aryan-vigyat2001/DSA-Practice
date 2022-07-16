#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxLeft=0;
        int maxRight=0;
        int totalwater=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                maxLeft=max(maxLeft,height[l]);
                totalwater=totalwater+maxLeft-height[l];
                l++;
            }
            else
            {
                maxRight=max(maxRight,height[r]);
                totalwater=totalwater+maxRight-height[r];
                r--;
            }
        }
        return totalwater;
        
    }
};
int main()
{
    
    return 0;
}