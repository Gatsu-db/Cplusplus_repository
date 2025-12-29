#include <iostream>
using namespace std;

void inside()
{
	cout << "inside message\n" << endl;
}

int main()
{
	cout << "Start\n\n";
	inside();
	cout << "End\n";
	
}