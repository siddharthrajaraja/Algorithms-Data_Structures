# THIS IS KADANES ALGO = > MAXIMUM CONTIGUOUS SUBARRAY PROBLEM (DP) in O(n)
def kadanes(l):
    local_max=0
    global_max=0

    for i in range(0,len(l)):
        local_max=max(l[i],l[i]+local_max)
        if local_max>global_max:
            global_max=local_max
    return global_max
l=list(map(int,input().split()))
print(kadanes(l))
