def sos(S,k,R,w,x,M,K):
        x[k]=1      
        #print("start",x,w,S)
        if S+w[k]==M:
            print(x)
            x=K[:]
    #        print("if",x)
        elif S+w[k]+w[k+1]<=M:
            sos(S+w[k],k+1,R-w[k],w,x,M,K)
        if S+R-w[k]>=M and S+w[k+1]<=M:
            
            x[k]=0
            #print(k,x)
            sos(S,k+1,R-w[k],w,x,M,K)
        return 
            
if __name__=="__main__":
        
    n=int(input("Enter number of elements int the list:"))
    print("Enter elements : ")
    l=list(map(int,input().split()))
    vis=[]
    k=[]
    for i in range(0,n):
        vis.append(0)
        k.append(0)
    M=int(input("Enter required Sum: "))
    S=sum(l)

    sos(0,0,S,l,vis,M,k)
    
