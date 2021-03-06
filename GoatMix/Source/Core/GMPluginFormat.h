/*
  ==============================================================================

    GMPluginFormat.h
    Created: 25 Sep 2017 12:34:59am
    Author:  Jonathon Racz

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class GMPluginFormat :
    public AudioPluginFormat
{
public:
    GMPluginFormat(AudioProcessorValueTreeState& state);
    ~GMPluginFormat() {}

    String getName() const override                                                     { return "Internal"; }
    bool fileMightContainThisPluginType(const String&) override                         { return true; }
    FileSearchPath getDefaultLocationsToSearch() override                               { return {}; }
    bool canScanForPlugins() const override                                             { return false; }
    void findAllTypesForFile(OwnedArray <PluginDescription>&, const String&) override   {}
    bool doesPluginStillExist(const PluginDescription&) override                        { return true; }
    String getNameOfPluginFromIdentifier(const String& fileOrIdentifier) override       { return fileOrIdentifier; }
    bool pluginNeedsRescanning(const PluginDescription&) override                       { return false; }
    StringArray searchPathsForPlugins(const FileSearchPath&, bool, bool) override       { return {}; }

    void getAllPluginsInExpectedParameterOrder(OwnedArray<PluginDescription>& array);

    PluginDescription gainDesc, compressorDesc, reverbDesc, distortionDesc, eqDesc;

private:
    bool requiresUnblockedMessageThreadDuringCreation(const PluginDescription&) const noexcept override { return false; }
    void createPluginInstance(const PluginDescription& desc,
                              double initialSampleRate,
                              int initialBufferSize,
                              void* userData,
                              void (*callback)(void*, AudioPluginInstance*, const String&)) override;

    AudioProcessorValueTreeState& state;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GMPluginFormat)
};
