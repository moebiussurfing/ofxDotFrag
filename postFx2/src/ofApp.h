#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxDotFrag.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void openCam();

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

    string path;
    int mode;
    float nCursor;

    ofImage img;

    ofVideoGrabber vidGrabber;
    vector<string> arguments;
    bool bCamOpen;
    bool bDisplayFps;
    bool bDrawGui;

	//-

    ofFbo fbo_VideoFx;
    ofxPanel gui_VideoFx;
    ofx::dotfrag::Monochrome frag1;
    ofx::dotfrag::HSB frag2;
    ofx::dotfrag::ThreeTones frag3;


    // change the name to test different shaders
    //ofx::dotfrag::InvertStrobe frag;
    //ofx::dotfrag::Twist frag;
    //ofx::dotfrag::Delay frag;
    //ofx::dotfrag::EchoTrace frag;
    //ofx::dotfrag::Mirror frag;
    //ofx::dotfrag::MirrorAxis frag;
    //ofx::dotfrag::RadialRemap frag;
    //ofx::dotfrag::Turbolence frag;
    //ofx::dotfrag::Live frag;
};
