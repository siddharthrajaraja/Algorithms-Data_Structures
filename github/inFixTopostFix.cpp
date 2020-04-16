#include<bits/stdc++.h>
#include<cctype>
#define pushb push_back
#define popb pop_back
using namespace std;



int priority(char s){
    switch(s){
        
        case '^':return 2;
        case '*':return 1;
        case '/':return 1;
        case '+':return 0;
        case '-':return 0;
    }
    return -1;
}



int main(){
    int t;cin>>t;
    while(t--){
      string s;  int n;cin>>n>>s;
      fflush(stdin);fflush(stdout);
      vector<char>stack;
      string ans="";
      for(int i=0;s[i];i++){
          if(s[i]=='(')stack.pushb(s[i]);             // Case 1: ( push  
          else if(isalpha(s[i])){                     // Case 2: is operand push  
                                    ans+=s[i];
                                }
          else if (s[i]==')'){                        // Case 3: ) pop while popped element is not '('
                                while(stack.back()!='('){
                                    
                                    char ele=stack.back();
                                    stack.popb();
                                   
                                    ans+=ele;
                                }
                                stack.popb();

                            }
          else{                                      // Case 4 : operators 
                        if(stack.empty()){stack.pushb(s[i]);  }     // case 4a : if stack empty push incoming
                        else{
                            if(stack.back()=='(')stack.pushb(s[i]);          // Case 4b: if stack top '(' push  
                            else{
                                if(priority(s[i])<=priority(stack.back())){   // Case 4c : if priority(incoming) < priority(tos)  pop tos ans push incoming
                                            
                                            while(!stack.empty()){

                                                if(priority(s[i])<=priority(stack.back())){
                                                         ans+=stack.back();
                                                         stack.popb();
                                           
                                                }
                                                else{
                                                    break;
                                                }

                                            }

                                            stack.pushb(s[i]);
                                }
                                else{                                        // case 4d :  if priority(incoming) > priority(tos) push incoming
                                        stack.pushb(s[i]);

                                }
                            }
                        }
              }

            //  cout<<ans<<endl;
        
      }
        while(!stack.empty()){
            ans+=stack.back();
            stack.popb();
        }
        cout<<ans<<endl;


    }
    return 0;
}


