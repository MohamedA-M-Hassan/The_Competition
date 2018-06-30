//http://codeforces.com/contest/680/problem/B
#include "iostream"
#include "string"
using namespace std;


int main()
{
	int numberOfCities, index;
	
	cin >> numberOfCities >> index  ;
	index--;
	int frontFlag = index + 1 , backFlag = index-1 , counterOFcriminals=0;

	int * criminalsDistance;
	criminalsDistance = new int[numberOfCities];

	for (int i = 0; i < numberOfCities; i++) { cin >> criminalsDistance[i];  }

	// check for criminals in the same city with officer
	if (criminalsDistance[index] == 1) { counterOFcriminals++; }

	while (true)
	{
		if (backFlag >= 0 && frontFlag <= numberOfCities - 1)
		{
			if (criminalsDistance[backFlag] == 1 && criminalsDistance[frontFlag] == 1) { counterOFcriminals += 2; }
			backFlag--; 
			frontFlag++;
		}
		else if (backFlag < 0 && frontFlag <= numberOfCities - 1)
		{
			if (criminalsDistance[frontFlag] == 1) { counterOFcriminals++; }
			frontFlag++;
		}
		else if (backFlag >= 0 && frontFlag > numberOfCities - 1)
		{
			if (criminalsDistance[backFlag] == 1) { counterOFcriminals++; }
			backFlag--;
		}
		else
		{
			break;
		}
	}

	cout << counterOFcriminals;
	//system("pause");
	return 0;
	
}