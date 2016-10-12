#pragma once

#include <glfw3.h>

const int width = 600;
const int height = 600;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawCircle(const int& i0, const int& j0, int r, const float& red, const float& green, const float& blue)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if ((i - i0) * (i - i0) + (j - j0) * (j - j0) - r * r < 0 && (i - i0) * (i - i0) + (j - j0) * (j - j0) - (r - 3) * (r - 3) > 0)
			{
				drawPixel(i, j, red, green, blue);
			}
		}
	}
}

void drawVertical(const int& i0, const int& j0, const int& j1, const float& red, const float& green, const float& blue)
{
	if (j0 < j1)
	{
		for (int i = j0; i <= j1; i++)
		{
			drawPixel(i0, i, red, green, blue);
		}
	}
	else if (j0 > j1)
	{
		for (int i = j0; i >= j1; i--)
		{
			drawPixel(i0, i, red, green, blue);
		}
	}
}