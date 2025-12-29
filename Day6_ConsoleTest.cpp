#include <iostream>
using namespace std;

int globalnum = 5;

void testscope()
{
	
	cout << globalnum << endl;
}

int main()
{
	cout << globalnum << endl;

	testscope();

	return 0;
}