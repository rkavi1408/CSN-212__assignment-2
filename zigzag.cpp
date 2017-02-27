#include<iostream>
using namespace std;
int longseq(int s[],int n){
int b[n],c[n];int res=1;
for(int i=0;i<n;i++){b[i]=c[i]=1;}
for(int i=1;i<n;i++){

for(int j=0;j<i;j++){

if(s[i]>s[j]){
              b[i]=max(c[j]+1,b[i]);
             }
else if(s[j]>s[i]){
                   c[i]=max(b[j]+1,c[i]);
                  }
}
if(res<max(b[i],c[i]))res=max(b[i],c[i]);
}
return res;
}
int main(){
int n;
cout<<"enter n"<<endl;
cin>>n;
int a[n];
cout<<"enter n elements"<<endl;
for(int i=0;i<n;i++)cin>>a[i];
int l= longseq(a,n);
cout<<l<<endl;
return 0;
}
