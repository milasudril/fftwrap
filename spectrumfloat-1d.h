#ifdef __WAND__
target[name[spectrumfloat-1d.h]type[include]]
#endif

#ifndef FFT_SPECTRUMFLOAT1D_H
#define FFT_SPECTRUMFLOAT1D_H

#include "planfloat-1dr2c.h"
#include "planfloat-1dc2r.h"

#include <herbs/array_fixedsize/array_fixedsize.h>

namespace FFT
	{
	class SpectrumFloat_1d
		{
		public:

			SpectrumFloat_1d(size_t length_real):
				 data(length_real)
				,spectrum(PlanFloat_1dR2C::sizeOut(length_real))
				,plan_forward(data.begin(),spectrum.begin(),length_real)
				,plan_backward(spectrum.begin(),data.begin(),length_real)
				,norm(sqrt(length_real))
				{}



			size_t dataLength() const
				{return data.length();}

			PlanFloat_1dR2C::InputType* dataBegin()
				{return data.begin();}

			const PlanFloat_1dR2C::InputType* dataBegin() const
				{return data.begin();}

			PlanFloat_1dR2C::InputType* dataEnd()
				{return data.end();}

			const PlanFloat_1dR2C::InputType* dataEnd() const
				{return data.end();}

			void dataUpdate()
				{
				plan_backward.execute();
				normalize(data);
				}




			size_t spectrumLength() const
				{return spectrum.length();}

			PlanFloat_1dC2R::InputType* spectrumBegin()
				{return spectrum.begin();}

			const PlanFloat_1dC2R::InputType* spectrumBegin() const
				{return spectrum.begin();}

			PlanFloat_1dC2R::InputType* spectrumEnd()
				{return spectrum.end();}

			const PlanFloat_1dC2R::InputType* spectrumEnd() const
				{return spectrum.end();}

			void spectrumUpdate()
				{
				plan_forward.execute();
				normalize(spectrum);
				}



		private:
			Herbs::ArrayFixedsize< PlanFloat_1dR2C::InputType > data;
			Herbs::ArrayFixedsize< PlanFloat_1dC2R::InputType > spectrum;

			PlanFloat_1dR2C plan_forward;
			PlanFloat_1dC2R plan_backward;

			double norm;

			template<class T>
			void normalize(T& vals)
				{
				auto ptr=vals.begin();
				while(ptr!=vals.end())
					{
					*ptr/=norm;
					++ptr;
					}
				}
		};
	}

#endif
