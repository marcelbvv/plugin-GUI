/*
  ==============================================================================

    IntanThread.h
    Created: 9 Jun 2011 1:34:16pm
    Author:  jsiegle

  ==============================================================================
*/

#ifndef __INTANTHREAD_H_D9135C03__
#define __INTANTHREAD_H_D9135C03__

#include "../../../JuceLibraryCode/JuceHeader.h"
#include <ftdi.h>
#include <stdio.h>
#include "DataThread.h"

class SourceNode;

class IntanThread : public DataThread

{
public:
	IntanThread(SourceNode* sn);
	~IntanThread();

	bool foundInputSource();
	int getNumChannels();
	float getSampleRate();
	
private:

	struct ftdi_context ftdic;
	int vendorID, productID;
	int baudrate;
	bool isTransmitting;
	bool deviceFound;

	bool initializeUSB(bool);
	bool closeUSB();

	bool startAcquisition();
	bool stopAcquisition();
	
	unsigned char startCode, stopCode;
	unsigned char buffer[240]; // should be 5 samples per channel

	float thisSample[16];

	int ch;

	bool updateBuffer();

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IntanThread);
};


#endif  // __INTANTHREAD_H_D9135C03__
