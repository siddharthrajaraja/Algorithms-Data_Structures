import numpy
INF=100000000000
n=int(input("Enter number of vertices : "))
e=int(input("Enter number of edges : "))
E=[]
Arr=[]
dis=[]
path=[]
for i in range(0,n):
    path.append(-1)
    dis.append(INF)
dis[0]=0
for i in range(0,n):
    l=[]
    for j in range(0,n):
        if i!=j:
            l.append(INF)
        else:
            l.append(0)
    Arr.append(l)
#print(Arr)

print("Enter SOURCE DESTINATION WEIGHT : ")
while e!=0:
    s,d,w=map(int,input().split())
    E.append((s,d,w))
    Arr[s-1][d-1]=w
    
    e=e-1

for i in range(0,n):
    for j in range(0,len(E)):
        #print(E[j])
        u=E[j][0]-1
        v=E[j][1]-1
        w=E[j][2]
        if dis[u]+w<dis[v]:
            dis[v]=dis[u]+w
            path[v]=u+1
flag=0
for i in range(1,2):
    for j in range(0,len(E)):
        u=E[j][0]-1
        v=E[j][1]-1
        w=E[j][2]
        if dis[u]+w<dis[v]:
            dis[v]=dis[u]+w
            path[v]=u+1
            flag=1
            break
    if flag==1:
        break
    
if flag==1:
    print("Negative Cycle Found")
else:
        

    print( "Distance Array :" , numpy.array(dis))
    print( "Path Array : " , numpy.array( path))
"""
Enter number of vertices : 4
Enter number of edges : 5
Enter SOURCE DESTINATION WEIGHT : 
1 2 4
1 4 5
4 3 3
3 2 -10
2 4 5
Negative Cycle Found
>>> 
===================== RESTART: D:/PYTHON FILES/belman.py =====================
Enter number of vertices : 4
Enter number of edges : 4
Enter SOURCE DESTINATION WEIGHT : 
1 2 4
1 4 5
4 3 3
3 2 -10
Distance Array : [ 0 -2  8  5]
Path Array :  [-1  3  4  1]
"""
