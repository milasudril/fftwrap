#ifdef __WAND__
target[name[planfloat-1dc2r.o]type[object]dependency[fftw3f;external]]
#endif

#include "planfloat-1dc2r.h"
#include <fftw3.h>

FFT::PlanFloat_1dC2R::PlanFloat_1dC2R(InputType* buffer_in
	,OutputType* buffer_out,size_t n_elem)
	{
	fftwf_set_timelimit(1);
	plan=fftwf_plan_dft_c2r_1d
		(
		 n_elem
		,(fftwf_complex*)buffer_in
		,buffer_out
		,FFTW_MEASURE
		);
	}

void FFT::PlanFloat_1dC2R::execute()
	{
	fftwf_execute((fftwf_plan)plan);
	}

FFT::PlanFloat_1dC2R::~PlanFloat_1dC2R()
	{
	fftwf_destroy_plan((fftwf_plan)plan);
	}

void FFT::PlanFloat_1dC2R::execute(InputType* buffer_in,OutputType* buffer_out)
	{
	fftwf_execute_dft_c2r((fftwf_plan)plan,(fftwf_complex*)buffer_in,buffer_out);
	}

