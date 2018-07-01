#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<string> split_string(string input_string) {

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

int main()
{
	string  line1,line2;
	getline(cin, line1);
	getline(cin, line2);
	int n= stoi(split_string(line1)[0]);
	int h= stoi(split_string(line1)[1]);
	vector<string> heights = split_string(line2);
	int width =0;
	for(int i =0;i<n;i++){
		if (stoi(heights[i])>h)
			width +=2;
		else 
			width +=1;
	} 
	cout<<width;
}