//http://codeforces.com/problemset/problem/26/A
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int getNoOfDistinctFactors(int n){
  int tmp = n, cnt = 0;
  for(int i=2; i*i<=n; i++){
    bool distict = true;
    while(tmp % i == 0){
      tmp /= i;
      if (distict) {
          cnt ++;
          distict = false;
      }
    }
    
  }
  
if(tmp != 1){
    cnt++;
  }
  return cnt;
}

int main()
{
    string  line1;
	getline(cin, line1);
	int n= stoi(line1);
	int count =0;
	for (int i = 6 ; i<=n;i++) {
	    if (getNoOfDistinctFactors(i) == 2) {
	       count ++;
	    }
	}
	//getNoOfDistinctFactors(16);
	std::cout << count << std::endl;
	
}