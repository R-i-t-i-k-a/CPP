//g prep

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getNumber(string str,int& index){
  int x = 0;
  int sign = 1;
  while(str[index]!=',' && str[index]!='\0'){
    if(str[index] == ' '){
      index++;
      continue;
    }
    if(str[index] == '-'){
      index++;
      sign = -1;
      continue;
    }
    x = x * 10 + (str[index]-48);
    index++;
  }
  x*=sign;
  if(str[index]==','){
    index++;
  }
  //cout<<"Passed get number function";
  return x;
}

vector<int> convertToArray(string str){
  vector<int> arr;
  int index=0;
  int x = 0;
  while(str[index]!='\0'){
    x = getNumber(str, index);
    arr.push_back(x);
  }
  //cout<<"passed convert to array function";
  return arr;
}

string FindIntersection(string strArr[]) {
  // in order to access element of each list - > 0,3,6,9... are indexes
  vector<int> array1 = convertToArray(strArr[0]);
  vector<int> array2 = convertToArray(strArr[1]);
  
  string answer = "";

  int len1 = array1.size();
  int len2 = array2.size();

  int index1 = 0, index2 = 0;
  while(index1<len1 && index2<len2){
    if(array1[index1] == array2[index2]){
      answer += to_string(array1[index1]);
      index1++;
      index2++;
      if(index1!=len1 && index2!=len2){
        answer += ',';
      }
    }else if(array1[index1] < array2[index2]){
      index1++;
    }else{
      index2++;
    }
  }
  if(answer[answer.length()-1]==','){
    answer.pop_back();
  }
  if(answer == ""){
    return "false";
  }
  return answer;
}

int main(void) { 
   
  // keep this function call here
  string A[2] = {"",""};
  cout << "Enter the first list of integers separated by commas: ";
  getline(cin, A[0]);
  cout << "Enter the second list of integers separated by commas: ";
  getline(cin, A[1]);

  cout << FindIntersection(A);
  return 0;
    
}