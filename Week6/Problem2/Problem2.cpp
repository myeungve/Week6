#include <iostream>
#include <string>

template<class myVector>
class Vector2D
{
public:
	myVector x_, y_;

	Vector2D(const myVector& x_input, const myVector& y_input)
		: x_(x_input), y_(y_input)
	{}

	void print()
	{
		std::cout << x_ << " " << y_ << std::endl;
	}
};

int main()
{
	Vector2D<int> int_vector(1, 1);
	int_vector.print();

	Vector2D<float> float_vector(1.1f, 1.1f);
	float_vector.print();

	Vector2D<double> double_vector(1.1, 1.1);
	double_vector.print();
	
	// ...

	return 0;
}