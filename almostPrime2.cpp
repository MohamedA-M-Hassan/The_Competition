#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> split_string(string input_string) {

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<int> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(stoi(input_string.substr(i, pos - i)));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(stoi(input_string.substr(i, min(pos, input_string.length()) - i + 1)));

    return splits;
}

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
  
if(tmp != 1 && tmp != n){
    cnt++;
  }
  return cnt;
}

int main()
{
    string  line1;
	getline(cin, line1);
	int n= stoi(line1);
	for(int i =0 ; i<n;i++) {
	    string line;
	    getline(cin, line);
	    int lower = split_string(line)[0];
	    int higher = split_string(line)[1];
	    int count =0;
	    if (lower <4) {
	        lower =4;
	    }
	    for (int i = lower ; i<=higher;i++) {
	        if (getNoOfDistinctFactors(i) == 1) {
	            count ++;
	        }
	    }
	    //getNoOfDistinctFactors(16);
	    std::cout << count << std::endl;
	}
	
	
}