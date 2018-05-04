/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class WavetableVstAudioProcessorEditor  : public AudioProcessorEditor,
					public Slider::Listener
{
public:
    WavetableVstAudioProcessorEditor (WavetableVstAudioProcessor&);
    ~WavetableVstAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    void sliderValueChanged (Slider* slider);
    WavetableVstAudioProcessor& processor;
    Slider freqSlider;
    Slider detuneSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WavetableVstAudioProcessorEditor)
};
