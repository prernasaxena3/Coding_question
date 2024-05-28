#include <bits/stdc++.h> 
using namespace std;
//Question - Minimum Cost To Make String Valid

int findMinimumCost(string str) {
  //ODD CONDITION
  if(str.length()%2 == 1){
    return -1;
  } 
  stack<char>s;
  for(int i = 0;i<str.length();i++){
  char ch = str[i];
      if(ch == '{'){
        s.push(ch);
      } 
      else {

        //ch is  close braces
        if (!s.empty() && s.top() == '{'){
          s.pop();
        }
        else{
            s.push(ch);
        }
      }
  }

  //Stack invalid expression
  int open = 0;
  int close = 0;
  while(!s.empty()){
    if(s.top() == '{'){
      open++;
    }else{
      close++;
    }
    s.pop();
  }

  int ans = (open+1)/2  + (close+1)/2;
  return ans;
}