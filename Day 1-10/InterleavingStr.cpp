#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];
class Solution {
public:
    bool helper(string s1,string s2,string s3,int i,int j)
    {
        if(s1.length()==i && s2.length()==j)
        {
            return true;
        }
        bool temp=false;
        if(dp[i][j]!=-1)
        {
            return bool(dp[i][j]);
        }
        if(s1[i]==s3[i+j] && s2[j]==s3[i+j])
        {
            cout<<"here"<<endl;
            return dp[i][j]=temp=helper(s1,s2,s3,i+1,j)||helper(s1,s2,s3,i,j+1);
        }
        if(s1[i]==s3[i+j])
        {
            cout<<"Here1"<<endl;
            return dp[i][j]=temp=helper(s1,s2,s3,i+1,j);
        }
        if(s2[j]==s3[i+j])
        {
            cout<<"Here2"<<endl;
            return dp[i][j]=temp=helper(s1,s2,s3,i,j+1);
        }
        return dp[i][j]=temp;
    }
    bool isInterleave(string s1, string s2, string s3) {
         if(s1.length()==0  && s2.length()==0 && s3.length()==0 )
        {
            return true;
        }
        if(s3.length()!=(s1.length()+s2.length()))
        {
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,s3,0,0);
        
    }
};

int main()
{
    string s1="abx";
    string s2="ghf";
    string s3="aghfbx";
    memset(dp,-1,sizeof(dp));
    if(s1.length()==0 || s2.length()==0 || s3.length()==0 || s3.length()!=(s1.length()+s2.length()))
    {
        return false;
    }
    // cout<<helper(s1,s2,s3,0,0);

    
    return 0;
}