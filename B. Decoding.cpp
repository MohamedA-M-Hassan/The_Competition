//http://codeforces.com/contest/746/problem/B
#include "iostream"
#include "string"
using namespace std;


int main()
{
	int number, counterFront, counterBack;
	bool flag = true;
	 cin >> number ;
	 counterBack = number;
	 counterFront = 1;
	 string decodedString;
	 char * codedString;
		codedString = new char[number];
	 cin >> decodedString;

	 
	 for (int i = number; i > 0; i--)
	 {
		 if (flag == true)  { codedString[number - counterFront] = decodedString[i - 1]; counterFront++; flag = false; }
		 else { codedString[number - counterBack] = decodedString[i - 1];   counterBack--;  flag = true; }
	}
	 for (int i = 0; i < number; i++)
	 {
		 cout << codedString[i];
	 }
	  
//	 system("pause");
	return 0;
	
}