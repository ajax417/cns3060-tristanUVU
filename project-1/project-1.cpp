#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char* argv[])
{
	cout << "Tristan Wagstaff" << endl;
	cout << "CS3060" << endl;
	for (int i = 1; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}
