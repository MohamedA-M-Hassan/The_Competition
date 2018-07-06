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
	string  n,line;
	getline(cin, n);
	getline(cin,line);
	int size = stoi(n);
	vector<int> heights = split_string(line);
	int maxCount=1;//at least one
	for(int i=0;i<size;i++) {
		int currentHeight=heights[i];
		int currentCount=1;
		//backward 
		for(int j=i-1;j>=0;j--){
			if(heights[j]<=currentHeight){
				currentCount++;
				currentHeight=heights[j];
			}
			else {
				break;
			}
		}
		currentHeight = heights[i];
		//froward
		for(int j=i+1;j<size;j++){
			if(heights[j]<=currentHeight){
				currentCount++;
				currentHeight=heights[j];
			}
			else {
				break;
			}
		}
		if(currentCount>maxCount)
			maxCount=currentCount;
	}
	cout<<maxCount;
	return 0;
}