#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main(){
    int n;
    cin>>n;

    // memoization - recursion
    // vector<int> dp(n+1, -1);
    // cout<<f(n,dp);
    

    // tabulation - space optimised
    int prev2 = 0;
    int prev1 = 1;
    for(int i=1; i<n; i++){
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    cout<<prev1;

    return 0;
}
