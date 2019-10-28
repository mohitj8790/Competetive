#include <iostream>
using namespace std;

int main() {
    int t=1;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int len = s.length();
        int dp[len+1][len+1];
        for(int k=0;k<len+1;k++){
            for(int j=0;j<len+1;j++){
                if(k==j && k>=1 && j>=1){
                    dp[k][j] = 1;
                }
                else dp[k][j] = 0;
            }
        }
        int l = 1;
        int maxi = 0;
        while(l<len){
            int k = 1;
            int j = k + l;
            for(;k<=len-l;k++,j++){
                if(s.at(k-1)==s.at(j-1)){
                    dp[k][j] = dp[k+1][j-1] + 2;
                }
                else{
                    dp[k][j] = max(dp[k][j-1], dp[k+1][j]);
                }
            }
            l++;
        }

        for(int j=1;j<=len-1;j++){
            if(dp[1][j]*dp[j+1][len] > maxi){
                maxi = dp[1][j]*dp[j+1][len];
            }
        }
        cout<<maxi<<"\n";

        
    }
	//code
	return 0;
}