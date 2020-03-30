#include<iostream>
#include<vector>

using namespace std;

std::vector<long long>factorials;

void findFactorials();


int main(){
    findFactorials();
    int t;std::cin>>t;
    while(t!=0){
        long long n ;std::cin>>n;
        std::cout<<factorials[n]<<"\n";
        t--;
    }


    return 0;
}

void findFactorials(){
    factorials.push_back(1);
    for(long long i=1;i<=100000;i++){
        factorials.push_back((factorials[factorials.size()-1]*i)%1000000007);

    }


}
