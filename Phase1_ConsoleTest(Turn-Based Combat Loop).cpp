#include <iostream>
using namespace std;
/*
	EnemyState enum
	----------------
	Represents the possible gameplay states an enemy can be in.
	Enums are used to avoid magic numbers and improve readability.
*/
enum Enemystate
{
	HEALTHY,
	HURT,
	CRITICAL,
	DEAD
};
/*
	Enemy struct
	------------
	Groups all data related to a single enemy into one unit.
	This mirrors how game entities are represented in real engines.
*/
struct Enemy
{
	int health;// Current health value
	Enemystate state;// Current gameplay state
};
/*
	Updatedamage
	-----------
	Updates the enemy's state based on its current health.
	This function contains all logic that decides how health maps to state.
*/
void updatedamage(Enemy& enemy)
{
	// If health is zero or below, the enemy is dead begin with the specifics in order to avoid them being ignored
	if (enemy.health <= 0)
	{
		enemy.state = DEAD; // ensure not to use == as it compares yet doesn't apply was previously being compared which caused the loop to become infinite
	}
	// Critical state when health is very low
	else if (enemy.health <= 20)
	{
		enemy.state = CRITICAL;
	}
	// Hurt state for mid-range health
	else if (enemy.health <=50)
	{
		enemy.state = HURT;
	}
	// Otherwise the enemy is healthy
	else
	{
		enemy.state = HEALTHY; // ensure you always assign to the correct variable was previously being assigned to enemy.health causing the health to become zero rather than healthy 
	}
}
/*
	PrintEnemy
	----------
	Outputs the enemy's index, health, and current state.
	Passed as const reference because it does not modify the enemy.
*/
void printenemy(const Enemy& enemy, int index)
{
	cout << "Enemy: " << index << "| Health: " << enemy.health<< " | " ;
	// Select output based on enemy state
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
	/*
		Main game loop.
		Continues running until all enemies are dead.
	*/
	while (true)
	{
		cout << "\n--- TURN " << turn << "---\n";
		// Assume all enemies are dead until proven otherwise
		bool alldead = true;
		// Process each enemy for this turn
		for (int i = 0; i < 3; i++)
		{
			
			if (enemies[i].state == DEAD)
				continue;// Skips enemies that are already dead

			// Apply damage to the enemy
			enemies[i].health -= 25
			// Update the enemy's state based on new health
			updatedamage(enemies[i]);
			// Display the enemy's current status
			printenemy(enemies[i], i);

			// If any enemy is still alive, the game continues
			if (enemies[i].state != DEAD)
				alldead = false;
		}

		if (alldead) // End the game if all enemies are dead
		{
			cout << "\nAll Enemies Dead\n";
			break;//this is the litchpin to wheather the game ends or not as it immediately exits the loop it is inside of. 
		}

		turn++; // intergrate the turn (++ essentialy means turn+1)

	}
	return 0;
}