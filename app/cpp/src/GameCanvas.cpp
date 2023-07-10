/*
* GameCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
 */


#include "GameCanvas.h"

#include <random>


GameCanvas::GameCanvas(gApp* root) : gBaseCanvas(root) {
  this->root = root;
}

GameCanvas::~GameCanvas() {
}

void GameCanvas::setup() {
  gLogi("GameCanvas") << "setup";
  x = (getWidth() - image.getWidth() / 2) / 2;
  y = 0;
  dx = 1;
  dy = 1;
  font.loadFont("FreeSans.ttf", 20);
  image.loadImage("glistengine_logo.png");
  text = "FPS: 0";
}

void GameCanvas::onEvent(gEvent& event) {
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

bool GameCanvas::onTouch(gTouchEvent& event) {
    gLogi("GameCanvas") << event.getInputs()[0].x << ", " << event.getInputs()[0].y;
    return false;
}

void GameCanvas::update() {
    if(paused) return;
    //	gLogi("GameCanvas") << "update";
    float deltaTime = root->getElapsedTime();
    x += 400.0f * dx * deltaTime;
    y += 400.0f * dy * deltaTime;
    gLogi("GameCanvas") << "update: " << deltaTime;
    bool reflect = false;
    if(x < 0) {
        x = 0;
        dx = 1;
    }
    if(y < 0) {
        y = 0;
        dy = 1;
    }
    if(x >= getWidth() - image.getWidth() / 2) {
        x = getWidth() - image.getWidth() / 2;
        dx = -1;
    }
    if(y >= getHeight() - image.getHeight() / 2) {
        y = getHeight() - image.getHeight() / 2;
        dy = -1;
    }
    text = "FPS: " + gToStr(root->getFramerate());
}

void GameCanvas::draw() {
    //gLogi("GameCanvas") << "draw";
    image.draw(x, y, 667 / 2, 80 / 2);
    font.drawText(text, 50, 50);
}

void GameCanvas::keyPressed(int key) {
  //	gLogi("GameCanvas") << "keyPressed:" << key;
}

void GameCanvas::keyReleased(int key) {
  //	gLogi("GameCanvas") << "keyReleased:" << key;
}

void GameCanvas::charPressed(unsigned int codepoint) {
  //	gLogi("GameCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void GameCanvas::mouseMoved(int x, int y) {
  //	gLogi("GameCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseDragged(int x, int y, int button) {
  //	gLogi("GameCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void GameCanvas::mousePressed(int x, int y, int button) {
}

void GameCanvas::mouseReleased(int x, int y, int button) {
  //	gLogi("GameCanvas") << "mouseReleased" << ", button:" << button;
}

void GameCanvas::mouseScrolled(int x, int y) {
  //	gLogi("GameCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseEntered() {
}

void GameCanvas::mouseExited() {
}

void GameCanvas::windowResized(int w, int h) {
}

void GameCanvas::showNotify() {

}

void GameCanvas::hideNotify() {

}

