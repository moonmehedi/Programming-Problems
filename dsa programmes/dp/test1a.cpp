#include <bits/stdc++.h>
using namespace std;

int values[100];
int weights[100];
int dp[100][100];


int knapsack(int c,int i){
    if(c==0 or i==0)
    return dp[c][i]=0;
    if(dp[c][i]!=-1)
    return dp[c][i];
    if(weights[i-1]>c){
        return dp[c][i]=knapsack(c,i-1);
    }

    return dp[c][i]=max(values[i-1]+knapsack(c-weights[i-1],i-1),knapsack(c,i-1));
}

int main()
{
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }

    
    int item,capacity;
    cin >> item>>capacity;
    for (int i = 0; i < item; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < item; i++)
    {
        cin >> weights[i];
    }

    int result = knapsack(capacity, item);
    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}