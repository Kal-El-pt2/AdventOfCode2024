#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    vector<int> a(1000),b(1000);
    for(int i=0;i<1000;++i){
        cin>>a[i]>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    map<int,int> mp;
    for(int i=0;i<1000;++i){
        mp[b[i]]++;
    }
    int sscore = 0;
    for(int i=0;i<1000;++i){
        sscore += a[i] * mp[a[i]];
    }
    cout<<sscore<<endl;
    return 0;
}
