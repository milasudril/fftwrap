#ifdef __WAND__

target[
	name[
		fft.exe
	]
	type[
		application
	]
	platform[
		win32
	]
]
#endif
#ifdef __WAND__

target[
	name[
		fft
	]
	type[
		application
	]
]
#endif


#include "fft.h"

#include <herbs/maindefault.h>

Herbs::Application* Herbs::Application::instanceCreate()
	{
	return new FFT::FFT();
	}
