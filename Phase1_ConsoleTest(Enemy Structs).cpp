#include <iostream>
using namespace std;

enum Estate
{
	Healthy,//0
	Hurt,//1
	Critical,//2
	Dead,//3
};

struct Enemy
{
	int health;
	Estate state;
};

int main()
{
	Enemy enemies[5] =
	{
		{100,Healthy},
		{75, Healthy},
		{40,Healthy},
		{15,Healthy},
		{5,Healthy},
	};

	for (int i = 0; i < 5; i++)
	{
		enemies[i].health -= 20;
		
		if (enemies[i].health <= 0)
		{
			enemies[i].state = Dead;
		}
		else if (enemies[i].health <= 20)
		{
			enemies[i].state = Critical;
		}
		else if (enemies[i].health <=50)
		{
			enemies[i].state = Hurt;
		}
		else
		{
			enemies[i].state = Healthy;
		}

		cout << "Enemy " << i << ": ";

		switch (enemies[i].state)
		{
		case Healthy: cout << "Healthy";
			break;
		case Hurt: cout << "Hurt";
			break;
		case Critical: cout << "Critical";
			break;
		case Dead: cout << "Dead";
			break;
		}

		cout << " (Health : " << enemies[i].health << ")" << endl;
	}
	return 0;
}