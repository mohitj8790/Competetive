#include<bits/stdc++.h>
using namespace std;

string decode(string str)
{
    int n=str.size();
    stack<char> st;
    stack<int> in;
    
    string ans="";
    
    for(int i=0;i<n;i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            string s1="";
            
            while(str[i]>='0' && str[i]<='9')
            {
                s1+=str[i];
                i++;
            }
            i--;
            in.push(stoi(s1));
        }
        
        else if(st.empty() || str[i]!=']')
        {
            st.push(str[i]);
        }
        
        else
        {
            string s2="";
            
            while(st.top()!='[')
            {
                s2+=st.top();
                st.pop();
            }
            st.pop();
            string s3="";
            
            int x=in.top();
            in.pop();
            for(int j=0;j<x;j++)
            {
                s3+=s2;
            }
            
            int len=s3.size();
            for(int j=len-1;j>=0;j--)
            {
                st.push(s3[j]);
            }
        }
    }
    
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin>>str;
    
    cout<<decode(str);
    return 0;
}