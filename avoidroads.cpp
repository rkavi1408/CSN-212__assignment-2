#include<iostream>
using namespace std;
int bad[101][101][2];
int main(){
int m,n;
cin>>m>>n;
int b;
int x1,y1,x2,y2;
cout<<"bad edges no"<<endl;
cin>>b;
cout<<"bad edges coordinates"<<endl;
while(b--){
cin>>x1>>y1>>x2>>y2;
if(x1==x2){
if(y1>y2)
bad[x1][y2][1]=1;
else
bad[x1][y1][1]=1;}
else if(y1==y2){
if(x1>x2)
bad[x2][y1][0]=1;
else
bad[x1][y1][0]=1;}
}
int dp[m+2][n+2];
for(int i=0;i<m+2;i++)
for(int j=0;j<n+2;j++)
dp[i][j]=0;
dp[m][n]=1;
for(int i=m;i>=0;i--){
for(int j=n;j>=0;j--){
if(bad[i][j][0]==1&&bad[i][j][1]==1)
dp[i][j]=dp[i][j];
else if(bad[i][j][1]==1)
dp[i][j]=dp[i][j]+dp[i+1][j];
else if(bad[i][j][0]==1)
dp[i][j]=dp[i][j]+dp[i][j+1];
else
dp[i][j]=dp[i][j]+dp[i+1][j]+dp[i][j+1];
}
}
cout<<dp[0][0];
return 0;
}
