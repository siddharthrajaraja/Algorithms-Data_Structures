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

ll max(ll a,ll b){
    return (a>b)?a:b;
}

ll kadanes(){
    ll cur_max=arr[0];
    ll ans=arr[0];
    for(int i=1;i<arr.size();i++){
        cur_max=max(arr[i],cur_max+arr[i]);
        ans=max(ans,cur_max);

    }
    return ans;

}

int main(){
    ll n;std::cin>>n;input(n);
    std::cout<<kadanes();
    return 0;
}
