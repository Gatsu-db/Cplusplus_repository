#include <iostream>
using namespace std;

enum Enemystate
{
	HEALTHY,
	HURT,
	CRITICAL,
	DEAD
};

struct Enemy
{
	int health;
	Enemystate state;
};

void updatedamage(Enemy& enemy)
{

	if (enemy.health <= 0)
	{
		enemy.state = DEAD; // ensure not to use == as it compares yet doesn't apply was previously being compared which caused the loop to become infinite
	}

	else if (enemy.health <= 20)
	{
		enemy.state = CRITICAL;
	}

	else if (enemy.health <=50)
	{
		enemy.state = HURT;
	}

	else
	{
		enemy.state = HEALTHY; // ensure you always assign to the correct variable was previously being assigned to enemy.health causing the health to become zero rather than healthy 
	}
}

void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy: " << index << "| Health: " << enemy.health<< " | " ;

	switch (enemy.state)
	{
	case HEALTHY: cout << "Health ";
		break;
	case HURT: cout << "Hurt ";
		break;
	case CRITICAL: cout << "Critical ";
		break;
	case DEAD: cout << "Dead ";
		break;
	}

	cout << endl;
}

int main()
{
	Enemy enemies[3] =
	{
	{ 100,HEALTHY },
	{ 75, HEALTHY },
	{ 40, HEALTHY }
	};

	int turn = 1;

	while (true)
	{
		cout << "\n--- TURN " << turn << "---\n";
		bool alldead = true;

		for (int i = 0; i < 3; i++)
		{
			if (enemies[i].state == DEAD)
				continue;

			enemies[i].health -= 25;
			updatedamage(enemies[i]);
			printenemy(enemies[i], i);

			if (enemies[i].state != DEAD)
				alldead = false;
		}

		if (alldead)
		{
			cout << "\nAll Enemies Dead\n";
			break;
		}

		turn++;

	}
	return 0;
}