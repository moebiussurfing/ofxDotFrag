#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDotFrag.h"

#undef GL_ES

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        int mode;
        bool bDisplayFps;
        bool bDrawGui;
		float nCursor;

        ofImage img;

        ofFbo fbo;
        
        ofxPanel gui;
		ofParameterGroup params_Mask{ "BLACK AND WHITE" };
		ofx::dotfrag::Monochrome frag1;
		ofx::dotfrag::HSB frag2;
        ofx::dotfrag::InvertStrobe frag3;
		ofParameter<bool> bReset{ "RESET",false };
		void Changed_bReset();
		ofEventListener listener_bReset;
};
