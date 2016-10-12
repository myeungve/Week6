#include <iostream>
#include <string>
#include <vector>
#include "Draw.h"

class DrawBox
{
public:
	void draw()
	{
		drawVertical(200, 200, 300, 0.0f, 0.0f, 1.0f);
		drawVertical(300, 200, 300, 0.0f, 0.0f, 1.0f);
		drawLine(200, 200, 300, 200, 0.0f, 0.0f, 1.0f);
		drawLine(200, 300, 300, 300, 0.0f, 0.0f, 1.0f);
	}
};

class DrawCircle
{
public:
	void draw()
	{
		drawCircle(400, 400, 50, 1.0f, 0.0f, 0.0f);
	}
};

class GeometricObjectInterface
{
public:
	virtual void draw() = 0;
};

template<class T_OPERATION>
class GeometricObject : public GeometricObjectInterface
{
public:
	void draw()
	{
		T_OPERATION operation;
		operation.draw();
	}
};

int main()
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;
	
	window = glfwCreateWindow(width, height, "2016112145", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		std::fill_n(pixels, width*height * 3, 1.0f);

		std::vector<GeometricObjectInterface*> obj_list;
		obj_list.push_back(new GeometricObject<DrawBox>);
		obj_list.push_back(new GeometricObject<DrawCircle>);
		for (auto itr : obj_list)
			itr->draw();

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		
		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}

	return 0;
}