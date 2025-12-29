#include <iostream>

using namespace std;

string name = "Bro";

void greetings();
void SayHello();

int main()
{
	greetings();
	greetings();
	SayHello();
	return 0;
}

void greetings() 
{
	cout << "hello " << name << " from a function\n\n";
}
void SayHello()
{
	cout << "Goodbye "<<name<<" from a function" <<endl;
}
