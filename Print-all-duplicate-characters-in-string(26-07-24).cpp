#include<bits/stdc++.h>
using namespace std;

void printDuplicates(string st){
  unordered_map<char,int> freq;
  for(int i=0;i<st.length();i++){
    char ch=st[i];
    freq[ch]++;
  }

  for(auto it:freq){
    if(it.second>1){
      cout<<it.first<<", frequency = "<<it.second<<endl;
    }
  }
}

int main(){
  string str=input("Enter a string");
  printDuplicates(str);
  return 0;
}
