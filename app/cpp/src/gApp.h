/*
 * gApp.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef EXAMPLES_TESTEXAMPLE_GAPP_H_
#define EXAMPLES_TESTEXAMPLE_GAPP_H_

#include "gAndroidApp.h"


class gApp : public gAndroidApp {
public:
	gApp();
	~gApp();

	void setup();
	void update();

	void start();
	void stop();

	void pause();
	void resume();
};

#endif /* EXAMPLES_TESTEXAMPLE_GAPP_H_ */
