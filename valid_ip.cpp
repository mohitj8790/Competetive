#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    if(s.size()>1 && s[0]=='0')
    {
        return false;
    }
    else if(stoi(s)<=255 && stoi(s)>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<string> validIP(string str)
{
    vector<string> ans;
    int n=str.size();
    if(n>12 ||n<4)
    {
        return ans;
    }
    
    for(int i=1;i<4;i++)
    {
        string first=str.substr(0,i);
        if(!isValid(first))
        {
            continue;
        }
        
        for(int j=1;i+j<n && j<4;j++)
        {
            string second=str.substr(i,j);
            if(!isValid(second))
            {
                continue;
            }
            
            for(int k=1;i+j+k<n && k<4;k++)
            {
                string third=str.substr(i+j,k);
                string fourth=str.substr(i+j+k);
                
                if(isValid(third) && isValid(fourth))
                {
                    string curr=first+"."+second+"."+third+"."+fourth;
                    ans.push_back(curr);
                }
            }
        }
    }
    
    return ans;
}

int main() 
{
    string str;
    cin>>str;
    vector<string> res=validIP(str);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
	return 0;
}