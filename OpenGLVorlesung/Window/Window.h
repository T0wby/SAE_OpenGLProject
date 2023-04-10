#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class CWindow
{
public:
	auto Initialize(void) const->const int;
	auto Run(void) const->const int;
	auto Finalize(void) const->const int;
};

#endif // !WINDOW_H
