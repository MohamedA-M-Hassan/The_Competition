
// http://codeforces.com/contest/734/problem/A
#include "iostream"
#include "string"
using namespace std;


int main()
{
	 int n , AntonCounter = 0 ,DinkinCounter = 0;
	 string playerGames;
	cin >> n ;
	 cin >>playerGames;

	for (int i = 0; i < n; i++)
	{
		if (playerGames[i] == 'A') { AntonCounter += 1; }
		else { DinkinCounter += 1; }
	}
	if (AntonCounter > DinkinCounter) { cout << "Anton"; }
	else if (AntonCounter < DinkinCounter) { cout << "Danik"; }
	else cout << "Friendship";

	//system("pause");
	return 0;
	
}