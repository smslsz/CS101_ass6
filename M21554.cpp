#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back({x,i});
    }
    sort(vec.begin(),vec.end());
    float time=0;
    for(int i=0;i<n;i++){
        cout<<vec[i].second+1<<' ';
        time+=vec[i].first*(n-i-1);
    }
    cout<<'\n'<<fixed<<setprecision(2)<<time/n<<'\n';
    return 0;
}