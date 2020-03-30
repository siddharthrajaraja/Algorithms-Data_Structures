class Solution {
public:
    int tribonacci(int n) {
            if(n==0)return 0;
            if(n==1)return 1;
            if(n==2)return 1;
            std::vector<int>arr={0,1,1};
            int i=2;
        
            while(n>2){
                arr.push_back(arr[i-2]+arr[i-1]+arr[i]);
                i++;
                n--;
            }
            return arr[i];
        
    }
};