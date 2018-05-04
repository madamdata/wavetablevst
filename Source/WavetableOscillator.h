class WavetableOscillator 
{
	public:
		WavetableOscillator(const AudioSampleBuffer& wavetableToUse)
			:wavetable (wavetableToUse),
			 tableSize (wavetable.getNumSamples() - 1)
	{
		jassert (wavetable.getNumChannels() == 1);
	}
		

		forcedinline float getNextSample(float freq, float sampleRate) 
		{
			auto adjustedtableSize = tableSize;
			auto index0 = (unsigned int) currentIndex;
			auto index1 = index0 + 1;
			auto frac = currentIndex - (float) index0;
			auto* table = wavetable.getReadPointer (0);
			auto value0 = table[index0];
			auto value1 = table[index1];
			auto currentSample = value0 + frac * (value1 - value0);
			

			float tableSizeOverSampleRate = tableSize / sampleRate; //calculate how much to scan over the table per sample (tableDelta) 
			tableDelta = freq * tableSizeOverSampleRate;

			if ((currentIndex += tableDelta) > tableSize) { //start from the beginning of the table)
				currentIndex -= tableSize;
			}
			return currentSample;
		}

	private:
		const AudioSampleBuffer& wavetable;
		const int tableSize;
		float currentIndex = 0.0f, tableDelta = 0.0f;
};

