#include <cstring>
#include "WavetableOscillator.h"
using namespace std;

class OscillatorBank
{
	public: 
		OscillatorBank()
		{
		}


		~OscillatorBank()
		{
		}

		void prepareToPlay(int numOsc, const AudioSampleBuffer& wavetableToUse, int sampleRate)
		{
			smoothedCenterFreq.reset((double)sampleRate, (double)3.0);
			smoothedCenterFreq.setValue(400, true);
			numberofOscillators = numOsc;
			for (auto i = 0; i < numberofOscillators; ++i)
			{
				auto* osc = new WavetableOscillator(wavetableToUse);
				auto* freq = new LinearSmoothedValue<float>;
				freq->reset((double)sampleRate, (double)1.0);
				freq->setValue(400, true);
				oscillators.add(osc);
				frequencies.add(freq);

			}
			level = 0.15f/numOsc;
			sampleRateCopy = sampleRate;
		}


		void setCenterFrequency(float freq) 
		{
			centerFreq = freq;
			updateFrequencies();
		}

		string getCenterFrequency() 
		{
			string output = "";
			for (auto i = 0; i < numberofOscillators; ++i)
			{
			}
		}


		void setDetune(float det)
		{
			detune = det;
			updateFrequencies();

		}

		void updateFrequencies()
		{
			for (int i = 0; i < oscillators.size(); ++i)
			{
				auto* freq = frequencies.getUnchecked(i);
				freq->setValue(centerFreq + (i * detune), false);
			};
		}


		forcedinline float getNextSample() 
		{
			float output = 0.0f;
			for (auto oscIndex = 0; oscIndex < oscillators.size(); ++oscIndex)
			{
				auto* osc = oscillators.getUnchecked (oscIndex);
				auto* freq = frequencies.getUnchecked (oscIndex);
				float smoothedFreq = freq->getNextValue();
				auto sample = osc->getNextSample(smoothedFreq, sampleRateCopy) * level;
				output += sample;
			}
			return output;
		}


	private:
		OwnedArray<WavetableOscillator> oscillators;
		int numberofOscillators;
		float centerFreq;
		float detune;
		float level = 0.0f;
		int sampleRateCopy;
		LinearSmoothedValue<float> smoothedCenterFreq;
		OwnedArray<LinearSmoothedValue<float>> frequencies;

};
