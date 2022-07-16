#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr=0;
        vector<int>spiral;
        int er=matrix.size()-1;
        int sc=0;
        int ec=matrix[0].size()-1;
        int y=0;
        int dir=0;
        while(sr<=er && sc<=ec)
        {
            if(dir==0)
            {
                for(int i=sc;i<=ec;i++)
                {
                    spiral.push_back(matrix[sr][i]);
                }
                sr++;
                
            }
            else if(dir==1)
            {
                for(int i=sr;i<=er;i++)
                {
                    spiral.push_back(matrix[i][ec]);
                }
                ec--;
                
            }
            else if(dir==2)
            {
                for(int i=ec;i>=sc;i--)
                {
                    spiral.push_back(matrix[er][i]);
                }
                er--;
                
            }
            else
            {
                
                for(int i=er;i>=sr;i--)
            {
                spiral.push_back(matrix[i][sc]);
            }
            sc++;
            }
            dir=(dir+1)%4;
            
        }
        return spiral;
    }
};

int main()
{
    
    return 0;
}