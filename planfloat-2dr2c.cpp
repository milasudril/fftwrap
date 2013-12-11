#ifdef __WAND__
target[name[planfloat-2dr2c.o]type[object]dependencies[fftw3f]]
#endif

#include "planfloat-2dr2c.h"
#include <fftw3.h>

FFT::PlanFloat_2dR2C::PlanFloat_2dR2C(Herbs::MatrixStorage<InputType>& buffer_in
	,Herbs::MatrixStorage<OutputType>& buffer_out)
	{
	plan=fftwf_plan_dft_r2c_2d
		(
		 buffer_in.nRowsGet()
		,buffer_in.nColsGet()
		,buffer_in.rowGet(0)
		,(fftwf_complex*)buffer_out.rowGet(0)
		,FFTW_MEASURE
		);
	}

void FFT::PlanFloat_2dR2C::execute()
	{
	fftwf_execute((fftwf_plan)plan);
	}

FFT::PlanFloat_2dR2C::~PlanFloat_2dR2C()
	{
	fftwf_destroy_plan((fftwf_plan)plan);
	}
