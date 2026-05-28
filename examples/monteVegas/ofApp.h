#pragma once

#include "ofMain.h"
#include "gsl_monte.h"
#include "gsl_monte_vegas.h"
#include "ofxGSL.h"
#include "gsl_math.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void monteVegasIntegrate(gsl_monte_function* f, double xLower[], double xUpper[], gsl_rng* range, int dimensions, int numCalls);

		
};
