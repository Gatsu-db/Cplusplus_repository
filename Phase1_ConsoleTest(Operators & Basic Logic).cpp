#include <iostream>
using namespace std;

int main()
{
	// Assignment
	int health = 100;
	int damage = 100;
	int lives = 0;

	//Arithmetic
	health = health - (damage*2); // minus, parenthesis and multiplication

	//Comparison

	bool isAlive = health > 0;

	//logical
	bool canrespawn = isAlive == false && lives > 0; // == and &&

	cout << "Health: " << health << "\n" << endl;
	cout << "Is Alive: " << isAlive << "\n" << endl;
	cout << "Can Respawn: " << canrespawn << "\n" << endl;

	return 0;
}