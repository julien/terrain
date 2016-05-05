#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

	// this sketch will draw a "terrain" formed
	// by a grid composed of quads

	// size of the terrain
	int w = 2000;
	int h = 1600;

	// number of columns and rows for our grid
	int cols, rows;

	// size of each "quad" in the grid
	static const int scl = 20;

	float flying = 0.0f;

	// 2D array of Z points for each vertex
	float** terrain;

public:
	void setup();
	void update();
	void draw();

	// void keyPressed(int key);
	// void keyReleased(int key);
	// void mouseMoved(int x, int y);
	// void mouseDragged(int x, int y, int button);
	// void mousePressed(int x, int y, int button);
	// void mouseReleased(int x, int y, int button);
	// void mouseEntered(int x, int y);
	// void mouseExited(int x, int y);
	// void windowResized(int w, int h);
	// void dragEvent(ofDragInfo dragInfo);
	// void gotMessage(ofMessage msg);

};
