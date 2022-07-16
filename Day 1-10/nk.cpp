// C++ implementation of the approach
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int subStringsStartingHere(string str, int n,
							int startIndex,unordered_map<string,vector<string>> &umap)
{
	int count = 0, i = 1;
	while (i <= n)
	{
		if (str.substr(0,i) ==
				str.substr(startIndex, i) && startIndex!=str.size()-1)
		{
			if(umap.find(str)!=umap.end())
            {
                umap[str].push_back(str.substr(0,i) );
            }
            else
            {
                vector<string>s2;
                s2.push_back(str.substr(0,i));
                umap[str]=s2;
            }
            count++;
		}
		else
			break;
		i++;
	}

	return count;
}
int countSubStrings(string str, int n,unordered_map<string,vector<string>> &umap)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{

		// If current character is equal to
		// the starting character of str
		if (str[i] == str[0])
			count += subStringsStartingHere(str,n,i,umap);
	}
	return count;
}
bool isPrefix(string prefix, string full)
{
    return prefix == full.substr(0, prefix.size());
}

int main()
{
    int n;
    cin>>n;
    vector<string>sss;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        sss.push_back(s);

    }
    unordered_map<string,vector<string>>umap;
    for(int i=0;i<sss.size();i++)
    {
        int sizee=sss[i].length();
        int j=(countSubStrings(sss[i], sizee,umap));
    }
    
    for(auto i:sss)
    {
        int score =0;
        vector<string>vec=umap[i];
        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        for(int k=0;k<vec.size();k++)
        {
            for(int j=0;j<sss.size();j++)
            {
                if(sss[j].compare(0, vec[k].size(), vec[k]) == 0)
                {
                    score+=1;
                }
            }
        }
        cout<<score<<endl;
    }
    


    

}

