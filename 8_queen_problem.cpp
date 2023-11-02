#include <bits/stdc++.h>
#include <cmath>
#include <bitset>
using namespace std;
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int k =1000000+10;
void dfs(int i,int j,vector<vector<char>>&v,bool &x,int ii,int jj){
    if(i<0||j<0) return;
    if(i>=8||j>=8) return;
    if(v[i][j]=='*') {
      if(i!=ii||j!=jj){x=true;
        return;}
        }
     if(v[i][j]=='*'){
     dfs(i - 1, j, v, x, ii, jj);
     dfs(i + 1, j, v, x, ii, jj);
     dfs(i, j - 1, v, x, ii, jj);
     dfs(i, j + 1, v, x, ii, jj);
     dfs(i - 1, j + 1, v, x, ii, jj);
     dfs(i + 1, j - 1, v, x, ii, jj);
     dfs(i - 1, j - 1, v, x, ii, jj);
     dfs(i + 1, j + 1, v, x, ii, jj);
     }
     else{
      int z;
      int y;
      z=i-ii;
      y=j-jj;
      dfs(i+z,j+y,v,x,i, j);
     }
}
signed main()
{
  vector<vector<char>>v;
  for(int i=0;i<8;i++){
    vector<char>v1;
    for(int j=0;j<8;j++){
      char x;
      cin>>x;
      v1.push_back(x);
    }
    v.push_back(v1);
  }
  bool x=false;
  int cnt=0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(v[i][j]=='*'){
        dfs(i,j,v,x,i,j);
        cnt++;
      }
    }
  }
  if(cnt<8){
    cout<<"invalid\n";
    return 0;
  }
  if(x) cout<<"invalid\n";
  else  cout<<"valid\n";
}
