#include<bits/stdc++.h>
using namespace std;

struct trieNode
{
    trieNode *child[26];
    int freq;
};

trieNode *insert(trieNode* root,string key)
{
    int ind;
    trieNode * curr=root;
    
    for(int i=0;i<key.size();i++)
    {
        ind=key[i]-'a';
        
        if(curr->child[ind]==NULL)
        {
            curr->child[ind]=new trieNode();
        }
        
        curr->child[ind]->freq++;
        
        curr=curr->child[ind];
    }
    
    return root;
}

int find(trieNode * root, string str)
{
    int ind;
    trieNode* curr=root;
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        ind=str[i]-'a';
        
        if(curr->child[ind]==NULL)
        {
            return 0;
        }
        
        curr=curr->child[ind];
        count++;
        
        if(count==str.size())
        {
            return curr->freq;
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<string> vec(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    
    string str;
    cin>>str;
    
    trieNode* root=new trieNode();
    
    for(int i=0;i<n;i++)
    {
        root=insert(root,vec[i]);
    }
    
    int k=find(root,str);
    cout<<k;
    return 0;
}