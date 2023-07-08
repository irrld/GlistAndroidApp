/*
* GameCanvas.h
*
*  Created on: May 6, 2020
*      Author: noyan
*/

#ifndef GAMECANVAS_H_
#define GAMECANVAS_H_

#include "gApp.h"
#include "gBaseCanvas.h"

class GameCanvas : public gBaseCanvas {
public:
	GameCanvas(gApp* root);
	virtual ~GameCanvas();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void charPressed(unsigned int codepoint);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseScrolled(int x, int y);
	void mouseEntered();
	void mouseExited();
	void windowResized(int w, int h);

	void showNotify();
	void hideNotify();

	void onEvent(gEvent&) override;
	bool onTouch(gTouchEvent&);
private:
	gApp* root;
	gImage image;
	gFont font;
	std::string text;
	int x, y;
	int xd, yd;
};

#endif /* GAMECANVAS_H_ */
