#include <bits/stdc++.h>
using namespace std;

void compute(int s,int x)
{
    int A=(s-x)/2;
    
    int a=0,b=0;
    
    for(int i=0;i<8*sizeof(s);i++)
    {
        unsigned int xi=(x &(1<<i));
        unsigned int ai=(A &(1<<i));
        
        if(xi ==0 && ai==0)
        {
            continue;
        }
        
        else if(xi==0 && ai>0)
        {
            a=((1<<i) |a);
            b=((1<<i) |b);
        }
        else if(xi>0 && ai==0)
        {
            a=((1<<i) |a);
        }
        else
        {
            cout<<"Not Possible";
            return;
        }
    }
    
    cout<<"a="<<a<<" b="<<b;
    
    
}

int main() 
{
	int s,x;
	cin>>s>>x;
	
	compute(s,x);
	return 0;
}