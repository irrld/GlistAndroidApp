/*
* gCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
 */


#include "gCanvas.h"

gCanvas::gCanvas(gApp* root) : gBaseCanvas(root) {
  this->root = root;
}

gCanvas::~gCanvas() {
}

void gCanvas::setup() {
    gLogi("gCanvas") << "setup";
    dx = 1;
    dy = 1;
    font.loadFont("FreeSans.ttf", 20);
    image.loadImage("glistengine_logo.png");
    imagewidth = image.getWidth() / 2;
    imageheight = image.getHeight() / 2;
    x = (getWidth() - imagewidth) / 2;
    y = 0;
    text = "FPS: 0";
}

void gCanvas::onEvent(gEvent& event) {
    gEventDispatcher dispatcher{event};

    dispatcher.dispatch<gTouchEvent>(G_BIND_FUNCTION(onTouch));
    dispatcher.dispatch<gAppPauseEvent>([this](gAppPauseEvent&) {
        paused = true;
        return false;
    });
    dispatcher.dispatch<gAppResumeEvent>([this](gAppResumeEvent&) {
        paused = false;
        return false;
    });
}

bool gCanvas::onTouch(gTouchEvent& event) {
    gLogi("gCanvas") << event.getInputs()[0].x << ", " << event.getInputs()[0].y;
    return false;
}

void gCanvas::update() {
    if(paused) return;
    //	gLogi("gCanvas") << "update";
    float deltaTime = root->getElapsedTime();
    x += 400.0f * dx * deltaTime;
    y += 400.0f * dy * deltaTime;
    if(x < 0) {
        x = 0;
        dx = 1;
    }
    if(y < 0) {
        y = 0;
        dy = 1;
    }
    if(x >= getWidth() - imagewidth) {
        x = getWidth() - imagewidth;
        dx = -1;
    }
    if(y >= getHeight() - imageheight) {
        y = getHeight() - imageheight;
        dy = -1;
    }
    text = "FPS: " + gToStr(root->getFramerate());
}

void gCanvas::draw() {
    //gLogi("gCanvas") << "draw";
    image.draw(x, y, imagewidth, imageheight);
    font.drawText(text, 50, 50);
}

void gCanvas::keyPressed(int key) {
  //	gLogi("gCanvas") << "keyPressed:" << key;
}

void gCanvas::keyReleased(int key) {
  //	gLogi("gCanvas") << "keyReleased:" << key;
}

void gCanvas::charPressed(unsigned int codepoint) {
  //	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
  //	gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
  //	gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mousePressed(int x, int y, int button) {
}

void gCanvas::mouseReleased(int x, int y, int button) {
  //	gLogi("gCanvas") << "mouseReleased" << ", button:" << button;
}

void gCanvas::mouseScrolled(int x, int y) {
  //	gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseEntered() {
}

void gCanvas::mouseExited() {
}

void gCanvas::windowResized(int w, int h) {
}

void gCanvas::showNotify() {

}

void gCanvas::hideNotify() {

}

