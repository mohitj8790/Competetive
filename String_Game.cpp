#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back

struct ent
{
    char alpha;
    int freq;
    ent(char p,int q) : alpha(p), freq(q) {}

};

string res(string str,int n,int k)
{
    stack<ent> st;
    
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        if(st.size()>0 && st.top().freq==k)
        {
            char curr=st.top().alpha;
            
            while(st.size()>0 && st.top().alpha==curr)
            {
                st.pop();
            }
        }
        
        if(st.size()>0 && st.top().alpha==ch)
        {
            st.push(ent(ch,st.top().freq+1));
        }
        
        else
        {

            st.push(ent(ch,1));
        }
    }
    
    
    if(st.size()>0 && st.top().freq==k)
    {
        char curr=st.top().alpha;
            
        while(st.size()>0 && st.top().alpha==curr)
        {
            st.pop();
        }
    }
        
    string ans="";
    
    while(st.size()>0)
    {
        ans+=st.top().alpha;
        st.pop();
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        
        string str;
        cin>>str;
        
        cout<<res(str,n,k)<<"\n";
    }
    return 0;
}