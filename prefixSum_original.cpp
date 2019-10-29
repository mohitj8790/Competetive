#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int>> original(vector<vector<int>> prefix)
{
    vector<vector<int>> vec(n,vector<int>(m));
    vec[0][0]=prefix[0][0];
    for(int j=1;j<m;j++)
    {
        vec[0][j]=prefix[0][j]-prefix[0][j-1];
    }
    
    for(int i=1;i<n;i++)
    {
        vec[i][0]=prefix[i][0]-prefix[i-1][0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            vec[i][j]=prefix[i][j]+prefix[i-1][j-1]-prefix[i-1][j]-prefix[i][j-1];
        }
    }
    
    return vec;
    
}

int main() 
{
    cin>>n>>m;
    vector<vector<int>>prefix(n,vector<int>(m));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>prefix[i][j];
        }
    }
    
    vector<vector<int>> ori=original(prefix);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ori[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}