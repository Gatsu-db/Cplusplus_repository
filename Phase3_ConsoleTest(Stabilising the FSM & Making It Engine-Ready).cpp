#include <iostream>
using namespace std;

enum EnemyState
{
	HEALTHY,HURT,CRITICAL,DEAD
};

struct Enemy
{
	int health;
	EnemyState state;
	EnemyState previousState;
};

EnemyState Determinenextstate(const Enemy& enemy)
{
	if (enemy.health <= 0)
		return DEAD;
	else if (enemy.health <= 20)
		return CRITICAL;
	else if (enemy.health <= 50)
		return HURT;
	else
		return HEALTHY;
}

void enemyaction(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " Decides to ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Act aggressive";
		break;
	case HURT: cout << "Defend Themselves";
		break;
	case CRITICAL:cout << "Attempt fleeing";
		break;
	case DEAD: cout << "be dead";
		break;
	}
}

void OnEnterstate(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << " entered ";
	switch (enemy.state)
	{
	case HEALTHY : cout << "Healthy\n";
		break;
	case HURT: cout << "Hurt\n";
		break;
	case CRITICAL:cout << "Critical\n";
		break;
	case DEAD: cout << "Dead\n";
		break;
	}
}

void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << "| Health: " << enemy.health << " |State ";
	switch (enemy.state)
	{
	case HEALTHY: cout << "Healthy\n";
		break;
	case HURT: cout << "Hurt\n";
		break;
	case CRITICAL:cout << "Critical\n";
		break;
	case DEAD: cout << "Dead\n";
		break;
	}
	cout << endl;
}

void Onenemyexit(const Enemy& enemy, int index)
{
	if (enemy.state == DEAD)
		return;

	cout << "Enemy " << index << " Exited ";

	switch (enemy.state)
	{
		case HEALTHY : cout << "Healthy";
		break;
	case HURT: cout << "Hurt";
		break;
	case CRITICAL:cout << "Critical";
		break;
	default:
		break;
	}
}

int main()
{
	Enemy enemies[3]
	{
		{100,HEALTHY,HEALTHY},{60,HEALTHY,HEALTHY},{40,HEALTHY,HEALTHY}
	};

	int turn = 1;
	while (true)
	{
	  cout << "\n--- TURN " << turn << " ---\n";
	  bool alldead = true;

	  for ( int i = 0; i <3; i++)
	  {
		  if (enemies[i].state == DEAD)
			  continue;

		  enemies.health -= 25;

		  EnemyState newstate = Determinenextstate(enemies[i]);

		  if (newstate != enemies[i].state)
		  {
			  Onenemyexit(enemies[i], i);
			  enemies[i].previousState = enemies[i].state;
			  enemies[i].state = newstate;
			  OnEnterstate(enemies[i], i);
		  }
		  printenemy(enemies[i], i);
		  enemyaction(enemies[i], i);
		  if (enemies[i].state != DEAD)
			  alldead = false;
	  }
	  if (alldead)
	  {
		  cout << "\nAll Enemies Dead\n";
		  break;
	  }
	  turn ++

	}
	return 0;
}

