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
	string  line1,line2;
	getline(cin, line1);
	getline(cin, line2);
	vector<int> line1Ints= split_string(line1);
	int booksCount = line1Ints[0];
	int freeMinutes = line1Ints[1];
	vector<int> booksTime = split_string(line2);
	int sum=0;
	//int count =0;
	int maxCount=0;
	int start =0;
	for(int i =0;i<booksCount;i++){
		if(sum+booksTime[i]<=freeMinutes){
			sum+=booksTime[i];
			if(i==booksCount-1){
				if(i-start+1>maxCount){
					maxCount=i-start+1;
				}
			}
		}
		else{
			//compare 
			if(i-start>maxCount){
				maxCount=i-start;
			}
			sum-=booksTime[start];
			start++;
			//to redo the check for this element to add it or not 
			i--;
		}
	}
	cout<<maxCount;
	//system("pause");
	return 0;
}