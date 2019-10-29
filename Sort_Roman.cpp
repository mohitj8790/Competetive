#include<bits/stdc++.h>
using namespace std;

int toRoman(string s)
{
    int n=s.size();
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            res+=50;
        }
        else if(s[i]=='X')
        {
            if(i<n-1 && s[i+1]=='L')
            {
                res-=10;
            }
            else
            {
                res+=10;
            }
        }
        else if(s[i]=='V')
        {
            res+=5;
        }
        else if(s[i]=='I')
        {
            if(i<n-1 && s[i+1]=='V' ||s[i+1]=='L')
            {
                res--;
            }
            else
            {
                res++;
            }
        }
    }
    
    return res;
}

bool comp(string a,string b)
{
    istringstream isA(a);
    istringstream isB(b);
    
    string stringA[2],stringB[2];
    string temp;
    int i=0;
    
    while(isA>>temp)
    {
        stringA[i++]=temp;
    }
    i=0;
    while(isB>>temp)
    {
        stringB[i++]=temp;
    }
    
    if(stringA[0]<stringB[0])
    {
        return true;
    }
    else if(stringA[0]>stringB[0])
    {
        return false;
    }
    else
    {
        return toRoman(stringA[1])<=toRoman(stringB[1]);
    }
}

int main()
{
    string names[6]={"Richard V","Henry VI","Edward II","Richard XXV","Henry IX","Edward LII"};
    sort(names,names+6,comp);
    for(int i=0;i<6;i++)
    {
        cout<<names[i]<<" ";
    }
    return 0;
}