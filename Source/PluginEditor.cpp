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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidSideUtilityAudioProcessorEditor::MidSideUtilityAudioProcessorEditor (MidSideUtilityAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    InputGainSlider.reset (new Slider ("Input Gain Slider"));
    addAndMakeVisible (InputGainSlider.get());
    InputGainSlider->setRange (0, 2, 0);
    InputGainSlider->setSliderStyle (Slider::Rotary);
    InputGainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    InputGainSlider->addListener (this);

    Left_MidPanSlider.reset (new Slider ("Left/Mid Pan Slider"));
    addAndMakeVisible (Left_MidPanSlider.get());
    Left_MidPanSlider->setRange (0, 1, 0);
    Left_MidPanSlider->setSliderStyle (Slider::Rotary);
    Left_MidPanSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    Left_MidPanSlider->addListener (this);

    Right_SidePanSlider.reset (new Slider ("Right/Side Pan Slider"));
    addAndMakeVisible (Right_SidePanSlider.get());
    Right_SidePanSlider->setRange (0, 1, 0);
    Right_SidePanSlider->setSliderStyle (Slider::Rotary);
    Right_SidePanSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    Right_SidePanSlider->addListener (this);

    StereoWidthSlider.reset (new Slider ("Stereo Width Slider"));
    addAndMakeVisible (StereoWidthSlider.get());
    StereoWidthSlider->setRange (0, 2, 0);
    StereoWidthSlider->setSliderStyle (Slider::Rotary);
    StereoWidthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    StereoWidthSlider->addListener (this);

    InputGainLabel.reset (new Label ("Input Gain Label",
                                     TRANS("Input Gain")));
    addAndMakeVisible (InputGainLabel.get());
    InputGainLabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    InputGainLabel->setJustificationType (Justification::centred);
    InputGainLabel->setEditable (false, false, false);
    InputGainLabel->setColour (TextEditor::textColourId, Colours::black);
    InputGainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Left_MidPanLabel.reset (new Label ("Left/Mid Pan Label",
                                       TRANS("Left/Mid Pan")));
    addAndMakeVisible (Left_MidPanLabel.get());
    Left_MidPanLabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    Left_MidPanLabel->setJustificationType (Justification::centred);
    Left_MidPanLabel->setEditable (false, false, false);
    Left_MidPanLabel->setColour (TextEditor::textColourId, Colours::black);
    Left_MidPanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Left_MidPanLabel->setBounds (160, 320, 150, 24);

    Right_SidePanLabel.reset (new Label ("Right/Side Pan Label",
                                         TRANS("Right/Side Pan")));
    addAndMakeVisible (Right_SidePanLabel.get());
    Right_SidePanLabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    Right_SidePanLabel->setJustificationType (Justification::centred);
    Right_SidePanLabel->setEditable (false, false, false);
    Right_SidePanLabel->setColour (TextEditor::textColourId, Colours::black);
    Right_SidePanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Right_SidePanLabel->setBounds (320, 320, 150, 24);

    StereoWidthLabel.reset (new Label ("Stereo Width Label",
                                       TRANS("Stereo Width")));
    addAndMakeVisible (StereoWidthLabel.get());
    StereoWidthLabel->setFont (Font (15.0f, Font::plain).withTypefaceStyle ("Regular"));
    StereoWidthLabel->setJustificationType (Justification::centred);
    StereoWidthLabel->setEditable (false, false, false);
    StereoWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    StereoWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    InputComboBox.reset (new ComboBox ("Input combo box"));
    addAndMakeVisible (InputComboBox.get());
    InputComboBox->setEditableText (false);
    InputComboBox->setJustificationType (Justification::centred);
    InputComboBox->setTextWhenNothingSelected (String());
    InputComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    InputComboBox->addItem (TRANS("Stereo Input"), 1);
    InputComboBox->addItem (TRANS("Mid/Side Input"), 2);
    InputComboBox->addListener (this);

    OutputComboBox.reset (new ComboBox ("Output combo box"));
    addAndMakeVisible (OutputComboBox.get());
    OutputComboBox->setEditableText (false);
    OutputComboBox->setJustificationType (Justification::centred);
    OutputComboBox->setTextWhenNothingSelected (String());
    OutputComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    OutputComboBox->addItem (TRANS("Stereo Output"), 1);
    OutputComboBox->addItem (TRANS("Mid/Side Output"), 2);
    OutputComboBox->addListener (this);

    LeftPhasetoggleButton.reset (new ToggleButton ("LeftMidPhase toggle button"));
    addAndMakeVisible (LeftPhasetoggleButton.get());
    LeftPhasetoggleButton->setButtonText (TRANS("Left/Mid Phase Invert"));
    LeftPhasetoggleButton->addListener (this);

    RightPhasetoggleButton.reset (new ToggleButton ("Right Side Phase toggle button"));
    addAndMakeVisible (RightPhasetoggleButton.get());
    RightPhasetoggleButton->setButtonText (TRANS("Right/Side Phase Invert"));
    RightPhasetoggleButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MidSideUtilityAudioProcessorEditor::~MidSideUtilityAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    InputGainSlider = nullptr;
    Left_MidPanSlider = nullptr;
    Right_SidePanSlider = nullptr;
    StereoWidthSlider = nullptr;
    InputGainLabel = nullptr;
    Left_MidPanLabel = nullptr;
    Right_SidePanLabel = nullptr;
    StereoWidthLabel = nullptr;
    InputComboBox = nullptr;
    OutputComboBox = nullptr;
    LeftPhasetoggleButton = nullptr;
    RightPhasetoggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidSideUtilityAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidSideUtilityAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    InputGainSlider->setBounds (0, 24, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    Left_MidPanSlider->setBounds (160, 208, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    Right_SidePanSlider->setBounds (320, 208, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    StereoWidthSlider->setBounds (448, 24, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    InputGainLabel->setBounds (0, 136, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    StereoWidthLabel->setBounds (448, 136, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    InputComboBox->setBounds ((getWidth() / 2) - (150 / 2), 80, 150, 24);
    OutputComboBox->setBounds ((getWidth() / 2) - (150 / 2), 136, 150, 24);
    LeftPhasetoggleButton->setBounds (160, 352, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    RightPhasetoggleButton->setBounds (320, 352, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidSideUtilityAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == InputGainSlider.get())
    {
        //[UserSliderCode_InputGainSlider] -- add your slider handling code here..
        //[/UserSliderCode_InputGainSlider]
    }
    else if (sliderThatWasMoved == Left_MidPanSlider.get())
    {
        //[UserSliderCode_Left_MidPanSlider] -- add your slider handling code here..
        //[/UserSliderCode_Left_MidPanSlider]
    }
    else if (sliderThatWasMoved == Right_SidePanSlider.get())
    {
        //[UserSliderCode_Right_SidePanSlider] -- add your slider handling code here..
        //[/UserSliderCode_Right_SidePanSlider]
    }
    else if (sliderThatWasMoved == StereoWidthSlider.get())
    {
        //[UserSliderCode_StereoWidthSlider] -- add your slider handling code here..
        //[/UserSliderCode_StereoWidthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MidSideUtilityAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == InputComboBox.get())
    {
        //[UserComboBoxCode_InputComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_InputComboBox]
    }
    else if (comboBoxThatHasChanged == OutputComboBox.get())
    {
        //[UserComboBoxCode_OutputComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_OutputComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MidSideUtilityAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == LeftPhasetoggleButton.get())
    {
        //[UserButtonCode_LeftPhasetoggleButton] -- add your button handler code here..
        //[/UserButtonCode_LeftPhasetoggleButton]
    }
    else if (buttonThatWasClicked == RightPhasetoggleButton.get())
    {
        //[UserButtonCode_RightPhasetoggleButton] -- add your button handler code here..
        //[/UserButtonCode_RightPhasetoggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidSideUtilityAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="MidSideUtilityAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="Input Gain Slider" id="498de5430f2986bc" memberName="InputGainSlider"
          virtualName="" explicitFocusOrder="0" pos="0 24 25% 25%" min="0.0"
          max="2.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Left/Mid Pan Slider" id="f9bbb89646c32b71" memberName="Left_MidPanSlider"
          virtualName="" explicitFocusOrder="0" pos="160 208 25% 25%" min="0.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Right/Side Pan Slider" id="58814b02cf0f3689" memberName="Right_SidePanSlider"
          virtualName="" explicitFocusOrder="0" pos="320 208 25% 25%" min="0.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Stereo Width Slider" id="c6afc40587b4bada" memberName="StereoWidthSlider"
          virtualName="" explicitFocusOrder="0" pos="448 24 25% 25%" min="0.0"
          max="2.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Input Gain Label" id="963a86f442baf744" memberName="InputGainLabel"
         virtualName="" explicitFocusOrder="0" pos="0 136 25% 6%" edTextCol="ff000000"
         edBkgCol="0" labelText="Input Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Left/Mid Pan Label" id="30cd4837fe75c51a" memberName="Left_MidPanLabel"
         virtualName="" explicitFocusOrder="0" pos="160 320 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Left/Mid Pan" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Right/Side Pan Label" id="ce98cb37456fcf07" memberName="Right_SidePanLabel"
         virtualName="" explicitFocusOrder="0" pos="320 320 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Right/Side Pan" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Stereo Width Label" id="3d483ed413f44d43" memberName="StereoWidthLabel"
         virtualName="" explicitFocusOrder="0" pos="448 136 25% 6%" edTextCol="ff000000"
         edBkgCol="0" labelText="Stereo Width" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="Input combo box" id="6a9160422bd98862" memberName="InputComboBox"
            virtualName="" explicitFocusOrder="0" pos="0Cc 80 150 24" editable="0"
            layout="36" items="Stereo Input&#10;Mid/Side Input" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="Output combo box" id="de98ef3bbaef0fd" memberName="OutputComboBox"
            virtualName="" explicitFocusOrder="0" pos="0Cc 136 150 24" editable="0"
            layout="36" items="Stereo Output&#10;Mid/Side Output" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="LeftMidPhase toggle button" id="22dbb725d88ec333" memberName="LeftPhasetoggleButton"
                virtualName="" explicitFocusOrder="0" pos="160 352 25% 6%" buttonText="Left/Mid Phase Invert"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Right Side Phase toggle button" id="e4d2f3fa38cbe7fc" memberName="RightPhasetoggleButton"
                virtualName="" explicitFocusOrder="0" pos="320 352 25% 6%" buttonText="Right/Side Phase Invert"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
