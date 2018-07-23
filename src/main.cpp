#include <iostream>

extern "C" void func();

int main()
{
	std::cout << "Hello, world! [from C++]" << std::endl;
	func();
	
	return 0;
}