#include <iostream>
#include <string>

template<class T_INPUT>
void print(const T_INPUT& i)
{
	std::cout << i << std::endl;
}

int main()
{
	print(1);
	print(2.345f);
	print("Hello World");

	return 0;
}