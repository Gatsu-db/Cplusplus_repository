#include <iostream>
using namespace std;
/*
	EnemyState enum
	----------------
	Represents the possible states an enemy can be in.
	Enums are used instead of numbers to make game logic readable and safe.
*/
enum Estate
{
	HEALTHY,
	HURT,
	CRITICAL,
	DEAD
};
/*
	Enemy struct
	------------
	Groups all data related to a single enemy.
	This mirrors how real games represent entities.
*/
struct Enemy
{
	int health;  // Current health of the enemy
	Estate state; // Current state (alive, hurt, dead, etc.)
};
/*
	ApplyDamage
	-----------
	Applies damage to an enemy and updates its state.
	Passed by reference so changes affect the original enemy.
*/
void applydamage(Enemy& enemy, int damage)
{
	// If the enemy is already dead, do nothing
	if (enemy.state == DEAD)
		return;
	// Reduce health by the damage amount
	enemy.health -= damage;
	
	// Update enemy state based on remaining health
	if (enemy.health <= 0)
	{
		enemy.state = DEAD;
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
		enemy.state = HEALTHY;
	}
}
/*
	PrintEnemy
	----------
	Outputs the enemy's current state and health.
	Passed as const reference because this function does not modify the enemy.
*/
void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy " << index << ": ";

	// Switch selects behavior/output based on enemy state
	switch (enemy.state)
	{
	case HEALTHY: cout << "healthy";
		break;
	case HURT: cout << "hurt";
		break;
	case CRITICAL: cout << "critical";
		break;
	case DEAD: cout << "dead";
		break;
	}
	// Display remaining health
	cout << " (Heath: " << enemy.health << ")" << endl;
}

int main()
{
	/*
	Create an array of enemies.
	Each enemy starts healthy with a different health value.
   */

	Enemy eneimies[5] =
	{
	    {100,HEALTHY},
	    {75,HEALTHY},
		{40,HEALTHY},
		{15,HEALTHY},
		{5, HEALTHY}
	};
	/*
		Simulate a damage tick.
		Each enemy takes damage and then gets printed.
	*/
	for (int i = 0; i < 5; i++)
	{
		applydamage(eneimies[i], 20);
		printenemy(eneimies[i], i);
	}
	return 0;
}

