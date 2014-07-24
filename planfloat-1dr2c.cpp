#ifdef __WAND__
target[name[planfloat-1dr2c.o]type[object]dependency[fftw3f;external]]
#endif

#include "planfloat-1dr2c.h"
#include <fftw3.h>

FFT::PlanFloat_1dR2C::PlanFloat_1dR2C(InputType* buffer_in
	,OutputType* buffer_out,size_t n_elem)
	{
	plan=fftwf_plan_dft_r2c_1d
		(
		 n_elem
		,(InputType*)buffer_in
		,(fftwf_complex*)buffer_out
		,FFTW_MEASURE
		);
	}

void FFT::PlanFloat_1dR2C::execute()
	{
	fftwf_execute((fftwf_plan)plan);
	}

FFT::PlanFloat_1dR2C::~PlanFloat_1dR2C()
	{
	fftwf_destroy_plan((fftwf_plan)plan);
	}
