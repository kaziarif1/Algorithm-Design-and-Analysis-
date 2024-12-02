#include<bits/stdc++.h>
using namespace std;
int dp [10] [10];
int knap01 (int n, int w,int profit [] , int wt []) {
    if (n == 0 || w == 0) return 0;
    if (dp[n][w] != -1) return dp[n][w];

    if (wt[n-1] > w)
        return dp [n] [w] = knap01((n-1) , w ,profit , wt);
    else
        return dp[n][w] = max(knap01(n-1, w, profit, wt),
			profit[n-1] + knap01(n-1, w-wt[n-1], profit, wt));
}
 int main () {
     int n, w; cin >> n ;
     int profit[n] , wt[n];
     for (int i = 0; i < n; ++i) {
        cin >> profit [i];
        cin >> wt[i];
     }
     cin >> w;
     memset (dp, -1, sizeof(dp));
     cout << knap01(n,w,profit,wt) << endl;
 }
