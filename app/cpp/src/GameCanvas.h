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
//#include "gGUIDimmer.h"
#include "gGUIDropdownList.h"
#include "gGUIFrame.h"
#include "gGUIGrid.h"
#include "gGUILineGraph.h"
#include "gGUIListbox.h"
#include "gGUIMenubar.h"
#include "gGUIPanel.h"
#include "gGUISizer.h"
#include "gGUITextbox.h"
#include "gGUIToolbar.h"
#include "gImage.h"


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

	void onGuiEvent(int guiObjectId, int eventType, std::string value1 = "", std::string value2 = "");

private:
	gApp* root;
	gGUIFrame frame;
	gGUISizer framesizer;
	gGUIPanel panel1, panel2, panel3;
	gGUISizer panel1sizer, panel2sizer, panel3sizer;
	gGUISizer toolbarsizer;
	gGUIText text;
	gGUITextbox box;
	gGUIListbox list;
	gGUIDropdownList dropdown;
	gGUIMenubar menubar;
	gGUIToolbar toolbar;
	gGUIToolbarButton toolbarbutton1, toolbarbutton2, toolbarbutton3, toolbarbutton4, toolbarbutton5;
	gGUIGrid grid;
	gGUILineGraph linegraph;
	//gGUIDimmer dimmer;
};

#endif /* GAMECANVAS_H_ */
