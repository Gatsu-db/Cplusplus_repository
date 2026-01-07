#include <iostream>
using namespace std;

int main()
{
	int Ehp[5] = { 100, 75, 40, 15, 5 };

	for (int i = 0; i<5; i++)
	{
		Ehp[i] -= 20;

		if (Ehp[i] <= 0) // must be first as it's the most specific parameter and if it weren't first would cause the an incorrect label ()
		{
			cout << "Enemy "<< i <<" is dead" << endl;
		}

		else if (Ehp[i] <= 20)
		{
			cout << "Enemy " << i << " is critical" << endl;
		}

		else if (Ehp[i]<=50)
		{
			cout << "Enemy " << i << " is hurt" << endl;
		}

		else
		{
			cout << "Enemy " << i << " is healthy" << endl;
		}
	}
	return 0;
}
