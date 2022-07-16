#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int helper(int e, int f, vector<vector<int>> &dp)
    {
        if (e < 2 || f < 2)
        {
            return f;
        }
        if (dp[e][f] != -1)
        {
            return dp[e][f];
        }
        int l = 1;
        int r = f;
        int mn = INT_MAX;
        while (l <= r)
        {
            int k = (l + r) / 2;
            int low, high;
            if (dp[e - 1][k - 1] != -1)
            {
                low = dp[e - 1][k - 1];
            }
            else
            {
                low = helper(e - 1, k - 1, dp);
                dp[e - 1][k - 1] = low;
            }
            if (dp[e][f - k] != -1)
            {
                high = dp[e][f - k];
            }
            else
            {
                high = helper(e, f - k, dp);
                dp[e][f - k] = high;
            }
            int tempans = 1 + max(low, high);
            mn = min(mn, tempans);
            if (low < high)
            {
                l = k + 1;
            }
            else
            {
                r = k - 1;
            }
        }
        return dp[e][f] = mn;
    }
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, dp);
    }
};
int main()
{
    

    return 0;
}
