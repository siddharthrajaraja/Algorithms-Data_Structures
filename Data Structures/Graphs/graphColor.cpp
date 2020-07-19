#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define mvll map<ll,vector<ll>>
#define pushb push_back
#define popf pop_front
#define REP(i,a,b) for(int i=a;i<b;i++)

void inputGraph(mvll&dic,int);

int main(){ 
    int nodes ;
    int edges;
    cin>>nodes>>edges;

    mvll dic;
    inputGraph(dic,edges);

    vll visited(nodes+1,0);
    vll color(nodes+1,-1);

    int i;
    int flag=0;
    REP(i,1,nodes){
        
        if(visited[i]==0){ // Node not visited :
         // visit node , push in queue, make BFS for every node check color visited if not, push in Queue after color applied.
         
         deque<int>Q={i};

         while(!Q.empty()){
            int front=Q.front();
            visited[front]=1;
            Q.popf();
            for(auto ele:dic[front]){

                if(visited[ele]==1){
                    // Node already visited ---> check its colors if(equaal return false)
                    if(color[ele]==color[front]){
                        flag=1;
                        break;
                    }
                }
                else{
                    // Node not visited ---> First time swap color of front and push ---> if(color match )return false ---> Swap color push in Q
                    if(color[ele]==-1){
                        color[ele]=!color[front];
                        Q.push_back(ele);
                    }
                    else{
                        if(color[ele]==color[front]){
                            flag=1;break;
                        }

                    }
                }

            }
            if(flag==1)break;


         }

            if(flag==1)break;


        }

    }
                string ans="YES";
            if(flag==1)ans="NO";

            cout<<ans;




    return 0;
}

void inputGraph(mvll & dic,int nodes){
    while(nodes--){
        ll u,v;cin>>u>>v;
        if(dic.find(u)==dic.end()){
            dic[u]={v};
        }
        else{
            dic[u].pushb(v);
        }

        if(dic.find(v)==dic.end()){
            dic[v]={u};
        }
        else{
            dic[v].push_back(u);
        }

    }
}