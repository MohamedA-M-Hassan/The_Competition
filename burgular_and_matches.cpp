#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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
	string  line1;
	getline(cin, line1);
	vector<int> line1Ints = split_string(line1);
	int n = line1Ints[0];
	int m = line1Ints[1];
	map<unsigned long long,unsigned long long> x;
	vector<int>matchesCount;
	for(int i =0;i<m;i++){
		getline(cin, line1);
		vector<int> line1Ints = split_string(line1);
		if( x[line1Ints[1]])
			x[line1Ints[1]] += line1Ints[0];
		else {
			x[line1Ints[1]] = line1Ints[0];
			matchesCount.push_back(line1Ints[1]);
		}
	}
	sort(matchesCount.rbegin(),matchesCount.rend());
	unsigned long long count =0;
	for(int i=0;i<m;i++){
		if(n<=0)
			break;
		if(n>=x[matchesCount[i]]){
			count+=matchesCount[i]*x[matchesCount[i]];
			n -= x[matchesCount[i]];
		}
		else {
			count+=matchesCount[i]*n;
			n=0;
		}

	}
	cout<<count;
	return 0;
}