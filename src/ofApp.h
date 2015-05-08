#pragma once

#include "ofMain.h"
#include "ofxFlocking.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        ofxFlocking flock;
        ofVideoPlayer bg;
    
    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;
    vector <ofImage> images;
      ofImage ol;
};
