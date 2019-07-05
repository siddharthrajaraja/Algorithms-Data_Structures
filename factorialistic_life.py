t=int(input())
ans=[1]
inp=[]
for T in range(0,t):
    n=int(input())
    inp.append(n)
inp.sort()
val=inp[-1]
    
    
for i in range(1,val):
    ans.append(ans[i-1]*(i+1)%(pow(10,9)+7))

for i in range(0,t):
    val=inp[i]
    if val==0:
        print(1)
    else:
            
        print(ans[val-1])
