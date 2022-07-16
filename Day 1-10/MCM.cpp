#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int tmp=INT_MAX;
int solve(vector<int> &arr,int i,int j)
{

    if(i>=j)
    {
        return 0;
    }
    for(int k=i;k<=j-1;k++)
    {
        int tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(tempans<tmp)
        {
            tmp=tempans;
        }
    }
    return tmp;
}

int main()
{
    vector<int> arr={40,30,20,10,50};
    int z=solve(arr,1,arr.size()-1);
    cout<<z;
    
    return 0;
}