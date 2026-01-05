#include <iostream>
using namespace std;

int main()
{
	int Ehp[3] = { 9000 , 41, 67 }; //this array has three slots its not dynamic

	for (int i = 0; i < 3; i++)
	{
		cout << "Enemy " << i
			<< " health: "
			<< Ehp[i] << endl; // this loop index lets you access each element and avoids copy paste and scales pretty nicely
		Ehp[i] -= 10;
	}

	cout << Ehp[0] << " is the First enemy as arrays count from zero" << endl; //first enemy as arrays count from zero

	return 0;

}


