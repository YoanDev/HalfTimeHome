/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class HalftimeAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::TextButton::Listener
{
public:
    HalftimeAudioProcessorEditor (HalftimeAudioProcessor&);
    ~HalftimeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void buttonClicked (juce::Button*) override;

private:
    
    juce::TextButton buttonOn;
    juce::TextButton buttonOff;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    HalftimeAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HalftimeAudioProcessorEditor)
};
