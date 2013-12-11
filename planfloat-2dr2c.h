#ifdef __WAND__
dependencies[planfloat-2dr2c.o]
target[name[planfloat-2dr2c.h]type[include]]
#endif

#ifndef PLANFLOAT_2DR2C_H
#define PLANFLOAT_2DR2C_H

#include <vector/vector2d.h>
#include <herbs/matrixstorage.h>
#include <complex>

namespace FFT
	{
	class PlanFloat_2dR2C
		{
		public:
			typedef std::complex<float> OutputType;
			typedef float InputType;
			
			static Vector::Vector2d<size_t>
			sizeOut(const Vector::Vector2d<size_t> size_in)
				{
				auto ret=size_in;
				ret.x=ret.x/2 + 1;
				return ret;
				}
			
			PlanFloat_2dR2C(Herbs::MatrixStorage<InputType>& buffer_in
				,Herbs::MatrixStorage<OutputType>& buffer_out);
			void execute();  
			~PlanFloat_2dR2C();
		
		private:
			void* plan;
		};
	}

#endif