#ifdef __WAND__
dependencies[planfloat-1dr2c.o]
target[name[planfloat-1dr2c.h]type[include]]
#endif

#ifndef PLANFLOAT_1DR2C_H
#define PLANFLOAT_1DR2C_H

#include <complex>

namespace FFT
	{
	class PlanFloat_1dR2C
		{
		public:
			typedef std::complex<float> OutputType;
			typedef float InputType;
			
			static size_t sizeOut(size_t size_in)
				{return size_in/2+1;}
			
			PlanFloat_1dR2C(InputType* buffer_in
				,OutputType* buffer_out, size_t n_elem);
			void execute();  
			~PlanFloat_1dR2C();
		
		private:
			void* plan;
		};
	}

#endif