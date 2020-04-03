#include<vector>
#include<iostream>
#define ll long long

std::vector<ll> arr;

void input(ll n){
    while(n!=0){
        ll ele;std::cin>>ele;
        arr.push_back(ele);
        n--;
    }

}


ll max(ll a,ll b,ll c){
   return ((a>b)? ((a>c)?a:c):((b>c)?b:c));
}

ll min(ll a,ll b,ll c){
    return ((a>b)?((b>c)?c:b):((a>c)?c:a));   
}

ll maxProductSubarray(){
    ll cur_max=arr[0];
    ll cur_min=arr[0];
    ll ans=arr[0];
    ll prev_min=arr[0];
    ll prev_max=arr[0];

    for(int i=1;i<arr.size();i++){
        cur_max=max( prev_max*arr[i] ,prev_min*arr[i],arr[i] );
        cur_min=min(prev_min*arr[i],prev_max*arr[i],arr[i]);
        ans=max(ans,cur_max,cur_min);
        prev_max=cur_max;
        prev_min=cur_min;
    }
    return ans;
}


int main(){
    ll n;std::cin>>n;input(n);
    std::cout<<maxProductSubarray();


    return 0;
}
