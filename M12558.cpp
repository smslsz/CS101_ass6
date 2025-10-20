#include <iostream>
#include <vector>

using namespace std;
int countp(vector<vector<int>> vec,int i, int j,int n,int m){
    int ret=0;
    if(j==0||vec[i][j-1]==0){
        ret++;
    }
    if(j==m-1||vec[i][j+1]==0){
        ret++;
    }
    if(i==0||vec[i-1][j]==0){
        ret++;
    }
    if(i==n-1||vec[i+1][j]==0){
        ret++;
    }
    return ret;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==1){
                ans+=countp(vec,i,j,n,m);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}