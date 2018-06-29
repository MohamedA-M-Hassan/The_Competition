//http://codeforces.com/contest/66/problem/B
#include "iostream"
#include "string"
using namespace std;


int main()
{
	int number;
	 cin >> number ;

	 if (number == 1 || number == 2) { cout << number; return 0; }
	 int * sections;
	 sections = new int[number];
	 int * countSections;
	 countSections = new int[number];

	 for (int i = 0; i < number; i++) { cin >> sections[i];		countSections[i] = 1; }


	 for ( int i = 0; i < number; i++)
	 {
		 // after 
		 // check only for all items except the last one as it doesn't have item after it. 
		 if (i != number - 1) {

			 for (int j = i + 1; j < number; j++)
			 {
				 if (sections[i] >= sections[j] && j == number - 1) 
					{ countSections[i]++; }
				 else if (sections[i] >= sections[j] && sections[j] <= sections[j-1] & j != number - 1)
				 { countSections[i]++; }
				 else 
				 { break; }
			 }
		 }
		 // before
		 // check only for all items except the first one as it doesn't have item after it.
		 if (i != 0) {
			 for (int j = i - 1; j >= 0; j--)
			 {
				 if (sections[i] >= sections[j] && j == 0) 
				 {  countSections[i]++; } 
				 else if (sections[i] >= sections[j] && sections[j] <= sections[j + 1] && j != 0) 
				 { countSections[i]++; }
				 else 
				 { break; }
			 }
		 }
	 }
	 

	 // get biggest one
	 int largestItem = countSections[0];
	 for (int i = 0; i < number; i++)
	 {
		 if (countSections[i] > largestItem)		largestItem = countSections[i];
	 }

	 cout << largestItem;
	// system("pause");
	return 0;
	
}