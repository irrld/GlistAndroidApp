/*
 * gApp.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef EXAMPLES_TESTEXAMPLE_GAPP_H_
#define EXAMPLES_TESTEXAMPLE_GAPP_H_

#include "gBaseApp.h"


class gApp : public gBaseApp {
public:
	gApp();
	~gApp();

	void setup();
	void update();

	void pause();
	void resume();
	void start();
	void stop();

};

#endif /* EXAMPLES_TESTEXAMPLE_GAPP_H_ */
