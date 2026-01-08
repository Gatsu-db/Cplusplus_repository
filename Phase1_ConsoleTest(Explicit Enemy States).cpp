#include <iostream>
using namespace std;

enum Estate //this is an enumerated statement and causes the words there to be treated as numbers whilst not being able to interact with numbers properly
{
	HEALTHY,//0
	HURT,//1
	CRITICAL,//2
	DEAD//3
};

int main()
{
	int Ehp[5] = { 100, 75, 40, 15, 5 };
	Estate enemystate[5];// this links the enumerated statement

	for (int i = 0; i < 5; i++)
	{
		Ehp[i] -= 20;

			if (Ehp[i] <= 0)
			{
				enemystate[i] = DEAD;
			}
			else if (Ehp[i] <=20)
			{
				enemystate[i] = CRITICAL;
			}
			else if (Ehp[i] <= 50)
			{
				enemystate[i] = HURT;
			}
			else
			{
				enemystate[i] = HEALTHY;
			}

			cout << "Enemy " << i << " state: ";

			switch (enemystate[i])
			{
			case HEALTHY: cout << "healthy"; break;
			case HURT: cout << "hurt"; break;
			case CRITICAL: cout << "critical"; break;
			case DEAD: cout << "Dead"; break;
			}// there's no need for a default as the output can only be one of thease 5 things

			cout << endl;
	}
	return 0;
}