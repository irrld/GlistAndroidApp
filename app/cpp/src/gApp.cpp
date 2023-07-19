/*
 * gApp.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#include "gApp.h"
#include "gCanvas.h"


gApp::gApp() {
}

gApp::~gApp() {
}

void gApp::setup() {
	gCanvas* cnv = new gCanvas(this);
	appmanager->setCurrentCanvas(cnv);
}

void gApp::update() {
}

void gApp::start() {
	gLogi("gApp") << "start";
}

void gApp::resume() {
	gLogi("gApp") << "resume";
}

void gApp::pause() {
	gLogi("gApp") << "pause";
}

void gApp::stop() {
	gLogi("gApp") << "stop";
}
