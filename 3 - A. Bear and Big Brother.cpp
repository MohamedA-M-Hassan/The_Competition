http://codeforces.com/contest/791/problem/A

#include "iostream"
#include "string"
using namespace std;


int main()
{
	 int limak,bob , counter = 0;
	 cin >> limak >> bob ;
	 
	 while (true)
	 {
		 if (limak > bob) { cout << counter;  break; }
		 else { limak *= 3; bob *= 2;  counter++; }
	 }
	//system("pause");
	return 0;
	
}