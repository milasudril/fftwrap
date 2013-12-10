#ifdef __WAND__

dependencies[
	fft.o
]
target[
	name[
		fft.h
	]
	type[
		include
	]
]
#endif

#ifndef guard_FFT_H
#define guard_FFT_H

#include <herbs/application.h>

namespace FFT
	{
	class FFT:public Herbs::Application
		{
		public:
			int run();
			void destroy();
		};
	}

#endif
