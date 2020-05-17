#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

void balance(priority_queue<ll>&maxHeap,ll & sizeMax,priority_queue<ll,vector<ll>,greater<ll>>&minHeap,ll & sizeMin){
    if(sizeMax-sizeMin==2){
            ll temp=maxHeap.top();maxHeap.pop();sizeMax--;
            minHeap.push(temp);
            sizeMin++;
    }
    else if(sizeMin-sizeMax==2){
            ll temp=minHeap.top();minHeap.pop();sizeMin--;
            maxHeap.push(temp);
            sizeMax++;
    }
}


int main(){
	priority_queue<ll>maxHeap;
	priority_queue<ll,vector<ll>,greater<ll>>minHeap;
	
    ll n;cin>>n;
    ll sizeMax=0;
    ll sizeMin=0;

    while(n!=0){
        ll ele;cin>>ele;

        if(maxHeap.empty()){
                maxHeap.push(ele);
                sizeMax++;
        
        }
        else{

            if(maxHeap.top()>=ele){
                maxHeap.push(ele);
                sizeMax++;
            }
            else{
                minHeap.push(ele);
                sizeMin++;

            }

            balance(maxHeap,sizeMax,minHeap,sizeMin);
        }

        if(sizeMax==sizeMin){
                cout<<(maxHeap.top()+minHeap.top())/2<<"\n";
        }
        else{
            if(sizeMax>sizeMin){
                cout<<maxHeap.top()<<"\n";
            }
            else{
                cout<<minHeap.top()<<"\n";
            }
        }


     n--;
    }
	
	
	return 0;
}