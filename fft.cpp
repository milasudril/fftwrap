#ifdef __WAND__
target[
	name[
		FFT.o
	]
	type[
		object
	]
	dependencies[FFTw3f]
]
#endif

#include "fft.h"
#include "planfloat-1dr2c.h"
#include <vector/vector.h>
#include <cmath>
#include <mathext.h>

int FFT::FFT::run()
	{
	Vector::Vector<float> buffer(32);
	Vector::Vector<std::complex<float> > buffer_out
		(PlanFloat_1dR2C::sizeOut(buffer.dimGet()));
	
	PlanFloat_1dR2C fftplan(buffer.begin(),buffer_out.begin(),buffer.dimGet());
	
	for(size_t k=0;k<buffer.dimGet();++k)
		{
		buffer[k]=sin(k*2*MathExt::PI/4);
		}
	
	fftplan.execute();
	
	for(size_t k=0;k<buffer_out.dimGet();++k)
		{
		printf("%.15g\n",std::abs(buffer_out[k]));
		}
		
	return STATUS_OK;
	}

void FFT::FFT::destroy()
	{
	delete this;
	}
