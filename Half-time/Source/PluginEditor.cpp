/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HalftimeAudioProcessorEditor::HalftimeAudioProcessorEditor (HalftimeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),buttonOn("On"),buttonOff("Off")
{
    buttonOn.addListener(this);
    buttonOff.addListener(this);
    addAndMakeVisible(buttonOn);
    addAndMakeVisible(buttonOff);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 120);
}

HalftimeAudioProcessorEditor::~HalftimeAudioProcessorEditor()
{
}

//==============================================================================
void HalftimeAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("", getLocalBounds(), juce::Justification::centred, 1);
}

void HalftimeAudioProcessorEditor::resized()
{
    buttonOn.setBounds(10, 10, getWidth() - 20, 40);
    buttonOff.setBounds(10, 70, getWidth() - 20, 40);
}

void HalftimeAudioProcessorEditor::buttonClicked (juce::Button* button)
{
    if(button == &buttonOn)
    {
        audioProcessor.mState = 2;
    }
    else
    {
        audioProcessor.mState = 1;
    }
}


