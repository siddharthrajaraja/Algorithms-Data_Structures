#include<algorithm>
#include<iostream>
#include<vector>
#include<deque>

#define MAX 1000

using namespace std;

std::vector<int>arr[MAX];
std::deque<int>queue;
std::vector<int>visited;


void input(int,int);
void printArray(int);
void performBFS(int,int);



int main(){
    int vertices;std::cin>>vertices;
    int edges; std::cin>>edges;
    input(edges,vertices);
    
    return 0;
}

void input(int edges,int vertices){
    for(int i=0;i<vertices;i++){
            visited.push_back(0);
            
            
    }
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            arr[i].push_back(-1);
        }
    }


    while(edges!=0){
        int u,v,w; std::cout<<"Enter source\tDestination\tWeight\n"; std::cin>>u>>v>>w;
        arr[u-1][v-1]=w;
        //arr[v-1][u-1]=w;
        edges--;
        printArray(vertices);
    }
    
    int start; std::cout<<"Enter start node : " ;std::cin>>start;
    performBFS(vertices,start);

}


void printArray(int vertices){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            std::cout<<arr[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

}

void performBFS(int vertices,int start){
        std::cout<<"BFS is : ";
        visited[start-1]=1;
        queue.push_back(start);
        int toPrint=0;

        while (queue.size()!=0)
        {   int u;u=queue.front();
            if(toPrint==0)
                std::cout<<queue.front()<<"\t";
            else std::cout<<queue.front()+1<<"\t";
            toPrint++;
            
            queue.pop_front();
            for(int v=0;v<vertices;v++){
                if(arr[u-1][v]!=-1 && visited[v]!=1){
                    
                    queue.push_back(v);
                    visited[v]=1;

                }
            }

            
        }
        

        

}