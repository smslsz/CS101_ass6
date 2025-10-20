#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct loc{
    int x;
    int y;
};
struct range{
    float l;
    float r;
};
range f(loc a,int d){
    float w=sqrt(d*d-a.y*a.y);
    return {a.x-w, a.x+w};
}
bool cmp(range a,range b){
    if(a.r!=b.r) return a.r>b.r;
    else return a.l>b.l;
}
int main(){
    int count=0;
    bool noans=0;
    while(true){
        count++;
        int n,d;
        cin>>n>>d;
        if(n==0&&d==0) {break;}
        vector<loc> locs(n);
        vector<range> ranges(n);
        for(int i=0;i<n;i++){
            cin>>locs[i].x>>locs[i].y;
        }
        for(int i=0;i<n;i++){
            if(locs[i].y>d){
                cout<<"Case "<<count<<": "<<-1<<'\n';
                noans=1;
                break;
            }
        }
        if(n==1) {cout<<"Case "<<count<<": "<<1<<'\n';continue;}
        if(noans==1){noans=0;continue;}
        for(int i=0;i<n;i++){
            ranges[i]=f(locs[i], d);
        }
        sort(ranges.begin(),ranges.end(),cmp);
        bool used[n]={};
        bool usedall=0;
        int ans=1;
        float rad=ranges[0].l;
        for(int i=1;i<n;i++){
            if(rad>ranges[i].r){
                rad=ranges[i].l;
                ans++;
            }
        }
        cout<<"Case "<<count<<": "<<ans<<'\n';
    }
    return 0;
}