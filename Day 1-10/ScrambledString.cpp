#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];
bool helper(string a,string b)
{
    if(a.compare(b)==1)
    {
        return true;
    }
    if(a.length()<=1)
    {
        return false;
    }
    bool flag=false;
    int len=a.length();
    for(int i=1;i<len;i++)
    {
        if((helper(a.substr(0,i),b.substr(0,i))==true && helper(a.substr(i,len-i),b.substr(i,len-i))==true)||(helper(a.substr(0,i),b.substr(len-i,i))==true && helper(a.substr(i,len-i),b.substr(0,len-i))==true))
        {
            flag=true;
            break;
        }
    }
    return flag;
}
int main()
{
    string a,b;
    cout<<"Enter the First String"<<endl;
    cin>>a;
    cout<<"Enter the Second String"<<endl;
    cin>>b;
    if(a.compare(b)==0)
    {
        cout<<"Scrambled Strings";
    }
    if(a.length()<=1)
    {
        cout<<"Not Scrambled Strings";
    }
    if(helper(a,b))
    {
        cout<<"Scrambled Strings";
    }
    return 0;
}