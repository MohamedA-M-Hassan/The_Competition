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


int main()
{
	string  line1,line2;
	getline(cin, line1);
	getline(cin,line2);
	vector<int> line1Ints = split_string(line1);
	int n = line1Ints[0];
	int a = line1Ints[1]-1;//index must start with zero
	vector<int> citiesCriminals = split_string(line2);
	int count=0;
	if(citiesCriminals[a])
		count++;
	int backwardIndex=a-1;
	int forwadIndex=a+1;
	while(backwardIndex>=0&&forwadIndex<n){
		if(citiesCriminals[forwadIndex]&&citiesCriminals[backwardIndex])
			count+=2;
		forwadIndex++;
		backwardIndex--;
	}
	while (forwadIndex<n){
		if(citiesCriminals[forwadIndex])
			count++;
		forwadIndex++;
	}
	while (backwardIndex>=0){
		if(citiesCriminals[backwardIndex])
			count++;
		backwardIndex--;
	}
	cout<<count;
	return 0;
}