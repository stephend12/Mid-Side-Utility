/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h" //reference the processor from the editor class.
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidSideUtilityAudioProcessorEditor  : public AudioProcessorEditor,
                                            public Slider::Listener,
                                            public ComboBox::Listener,
                                            public Button::Listener
{
public:
    //==============================================================================
    MidSideUtilityAudioProcessorEditor (MidSideUtilityAudioProcessor& p);
    ~MidSideUtilityAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	MidSideUtilityAudioProcessor& processor; //Allows access the processor class members.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> InputGainSlider;
    std::unique_ptr<Slider> Left_MidPanSlider;
    std::unique_ptr<Slider> Right_SidePanSlider;
    std::unique_ptr<Slider> StereoWidthSlider;
    std::unique_ptr<Label> InputGainLabel;
    std::unique_ptr<Label> Left_MidPanLabel;
    std::unique_ptr<Label> Right_SidePanLabel;
    std::unique_ptr<Label> StereoWidthLabel;
    std::unique_ptr<ComboBox> InputComboBox;
    std::unique_ptr<ComboBox> OutputComboBox;
    std::unique_ptr<ToggleButton> LeftPhasetoggleButton;
    std::unique_ptr<ToggleButton> RightPhasetoggleButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidSideUtilityAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
