/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WavetableVstAudioProcessorEditor::WavetableVstAudioProcessorEditor (WavetableVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    freqSlider.setRange(30,5000,1);
    //freqSlider.setSkewFactorFromMidPoint(500);
    freqSlider.addListener(this);
    addAndMakeVisible(&freqSlider);
    detuneSlider.setRange(0,40);
    detuneSlider.addListener(this);
    addAndMakeVisible(&detuneSlider);
    setSize (300, 200);
}

WavetableVstAudioProcessorEditor::~WavetableVstAudioProcessorEditor()
{
}

//==============================================================================
void WavetableVstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::black);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void WavetableVstAudioProcessorEditor::resized()
{
	freqSlider.setBounds(20,20,getWidth() - 20, 20);
	detuneSlider.setBounds(20,40,getWidth() - 20, 20);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void WavetableVstAudioProcessorEditor::sliderValueChanged (Slider* slider) {
	if (slider == &freqSlider) {
		processor.setCenterFreq(slider->getValue());
	}
	if (slider == &detuneSlider) {
		processor.setDetune(slider->getValue());
	}
}
