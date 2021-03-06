/*
  ==============================================================================

    MaxdBLabel.h
    Created: 30 Oct 2017 1:30:38am
    Author:  Jonathon Racz

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "GMLookAndFeel.h"
#include "../DSP/WindowedMeter.h"

class MaxdBLabel :
    public Label,
    public Timer
{
public:
    MaxdBLabel()
    {
        setJustificationType(Justification::centred);
        startTimerHz(5);
    }

    void setSource(WindowedMeter* _source)
    {
        jassert(_source);
        source = _source;
    }

private:
    void mouseUp(const MouseEvent& e) override
    {
        setText(Decibels::toString(0.0f), NotificationType::dontSendNotification);
        source->resetPeakOverall();
        Label::mouseUp(e);
    }

    void paint(Graphics& g) override
    {
        if (source && source->getClippingStatus())
            g.fillAll(findColour(GMLookAndFeel::ColourIds::meterClip));
        Label::paint(g);
    }

    void timerCallback() override
    {
        String newText;
        if (source)
            newText = Decibels::toString(source->getPeakOverall());
        else
            newText = "NO SOURCE";

        if (newText != getText())
        {
            setText(newText, NotificationType::dontSendNotification);
            repaint();
        }
    }

    WeakReference<WindowedMeter> source;
};
