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
    ll sum =0;

    for(int i=0;i<1000;++i){
        sum+= abs(a[i]-b[i]);
    }
    cout<<sum<<endl;
    return 0;
}
