#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

class Solution
{
public:
    int lps(string s)
    {
        int size = s.size();
        vi dp(size, 0);
        int i = 0; // i is lower pointer
        int j = 1;  // j is higher pointer

        while (j < size)
        {
            /*
                if ith character == jth character 
                the prefix and suffix matches
                increment i and j.
            */
           /*
                otherwise :
                    check the if i is zero i can't move back to match prefic and suffix
                    if i==0:
                        put dp[j]=0 , j++
                    else :
                        i=dp[i-1] // move the i pointer back to previous prefix-suffix match        
            */
            if (s[j] == s[i]) 
            {
                i++;
                dp[j] = i;
                j++;
            }
            else
            {
                if (i == 0)
                {
                    dp[j] = 0;
                    j++;
                }
                else
                {
                    i = dp[i - 1];
                }
            }
        }
        return dp.back();
    }
};

int main()
{

    string pattern;
    cin >> pattern;
    Solution *obj = new Solution();
    cout << obj->lps(pattern);
    return 0;
}