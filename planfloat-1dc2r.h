#ifdef __WAND__
dependency[planfloat-1dc2r.o]
target[name[planfloat-1dc2r.h]type[include]]
#endif

#ifndef PLANFLOAT_1DC2R_H
#define PLANFLOAT_1DC2R_H

#include <complex>

namespace FFT
	{
	class PlanFloat_1dC2R
		{
		public:
			typedef std::complex<float> InputType;
			typedef float OutputType;

			PlanFloat_1dC2R(InputType* buffer_in
				,OutputType* buffer_out, size_t n_elem);
			void execute();
			void execute(InputType* buffer_in,OutputType* buffer_out);

			~PlanFloat_1dC2R();

		private:
			void* plan;
		};
	}

#endif