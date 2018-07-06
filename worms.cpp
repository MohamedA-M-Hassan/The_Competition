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

int findPile(int x,vector<int>&pilesLabels,int start,int end){
	int mid = start + (end - start)/2;
	if (pilesLabels[mid]<=x){
		if (mid+1<=end){
			if (pilesLabels[mid+1]>x)
				return mid+1;
		} 
		else {
			return mid+1;
		}
	}
	else {
		return findPile(x,pilesLabels,start,mid-1);
	}
	return findPile(x,pilesLabels,mid+1,end);
}
int main()
{
	string  line1,line2,line3,line4;
	getline(cin, line1);
	getline(cin, line2);
	getline(cin, line3);
	getline(cin, line4);
	int pilesCount = stod(line1);
	vector<int> pilesContent = split_string(line2);
	int n = stod(line3);
	vector<int> choices = split_string(line4);
	int sum =1;
	//change to using labels 
	for (int i =0;i<pilesCount;i++) {
		int temp = pilesContent[i];
		pilesContent[i]=sum;
		sum+=temp;
	}
	for (int j=0;j<n;j++){
		cout<<findPile(choices[j],pilesContent,0,pilesCount-1)<<endl;
	}
	//system("pause");
	return 0;
}