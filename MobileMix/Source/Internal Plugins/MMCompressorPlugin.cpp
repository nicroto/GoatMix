/*
  ==============================================================================

    MMCompressorPlugin.cpp
    Created: 15 Sep 2017 11:01:31am
    Author:  Jonathon Racz

  ==============================================================================
*/

#include "MMCompressorPlugin.h"
#include "MMCompressorPluginEditor.h"

MMCompressorPlugin::MMCompressorPlugin(AudioProcessorValueTreeState& state) :
    MobileMixPluginInstance(state)
{
}

void MMCompressorPlugin::registerParameters()
{
    // Add parameters here via createParameter...
    paramCompressor = state.createAndAddParameter(addPrefixToParameterName("Compressor"),
                                                          addPrefixToParameterName("Compressor"),
                                                          "",
                                                          NormalisableRange<float>(0.0f, 1.0f, 0.1f),
                                                          1.0f,
                                                          nullptr,
                                                          nullptr);
}

AudioProcessorEditor* MMCompressorPlugin::createEditor()
{
    return new MMCompressorPluginEditor(*this);
}

void MMCompressorPlugin::prepareToPlay(double sampleRate, int maximumExpectedSamplesPerBlock)
{
    MobileMixPluginInstance::prepareToPlay(sampleRate, maximumExpectedSamplesPerBlock);
}

void MMCompressorPlugin::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    MobileMixPluginInstance::processBlock(buffer, midiMessages);
}
