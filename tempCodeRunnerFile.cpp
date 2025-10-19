#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,a;
    cin>>n;
    vector<int> vec;
    while(cin>>a){
        vec.push_back(a);
    }
    int m=vec.size()-1;
    vector<int> sum(m+1);
    sort(vec.begin(),vec.end());
    if(n<vec[0]){
        cout<<0;
        return 0;
    }
    sum[0]=vec[0];
    for(int i=1;i<=m;i++){
        sum[i]=sum[i-1]+vec[i];
    }
    int id=0;
    for(int j=0;j<m;j++){
        for(int i=0;i<=m;i++){
            if(sum[i]>n+sum[m]-sum[m-j]){
                id=max(id,i-j);
                break;
            }
        }
    }
    cout<<id<<'\n';
    return 0;
}