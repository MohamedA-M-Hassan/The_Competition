#include "iostream"
using namespace std;


int main()
{
	 int n = 0, h= 0 ,a = 0,width=0;
	cin >> n >> h;

	for (int i = 0; i < n; i++)
	{
		
		cin >> a;
		if (a > h)  width += 2; 
		else  width += 1; 
	}
	cout << width;
	//system("pause");
	return 0;
	
}