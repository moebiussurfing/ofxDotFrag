#include "ofApp.h"

// change the name of the shader in ofApp.h to test different shaders

// scope.png from wikipedia

//--------------------------------------------------------------
void ofApp::setup()
{
    img.load("scope.png");

    //ofSetLogLevel( OF_LOG_VERBOSE );
    //frag.allocate( fbo_VideoFx );

    ofBackground(0);
    mode = 2;
    nCursor = ofRandom(1.0f);
    bCamOpen = false;
    bDrawGui = true;
    bDisplayFps = true;

    gui_VideoFx.setup("", "videoFX_settings.xml", ofGetWidth()-202, 10);
    gui_VideoFx.setName("VIDEO FX");
	
	ofEnableArbTex();

    fbo_VideoFx.allocate(ofGetWidth(), ofGetHeight());
    frag1.allocate(fbo_VideoFx);
    frag2.allocate(fbo_VideoFx);
    frag3.allocate(fbo_VideoFx);

	ofEnableArbTex();


    gui_VideoFx.add(frag1.parameters);
    gui_VideoFx.add(frag2.parameters);
    gui_VideoFx.add(frag3.parameters);

    //gui_VideoFx.add(frag.parameters);
}

void ofApp::openCam()
{
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(640, 480);
}

void ofApp::windowResized(int w, int h)
{
    if (bDrawGui)
    {
        fbo_VideoFx.allocate(ofGetWidth(), ofGetHeight());
		gui_VideoFx.setPosition(10, 400);
    }
    else
    {
        fbo_VideoFx.allocate(ofGetWidth(), ofGetHeight());
    }

}

//--------------------------------------------------------------
void ofApp::update()
{
    fbo_VideoFx.begin();
    ofClear(0, 0, 0, 0);
    img.draw(0, 0);
    fbo_VideoFx.end();

    //frag.apply(fbo_VideoFx);
    frag1.apply(fbo_VideoFx);
    frag2.apply(fbo_VideoFx);
    frag3.apply(fbo_VideoFx);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    fbo_VideoFx.draw(0, 0);
    //frag.draw( 0, 0 );

    if (bDrawGui)
        gui_VideoFx.draw();
    ofSetColor(255);
    if (bDisplayFps)
        ofDrawBitmapString("fps=" + ofToString(ofGetFrameRate()), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key)
    {
        case 'g':
            bDrawGui = !bDrawGui;
            break;
        //case ' ':
        //    frag.active = true;
        //    break;
        //case 'r':
        //    frag.reload();
        //    break;
        case 'f':
            bDisplayFps = !bDisplayFps;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    //if (key == ' ')
    //    frag.active = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
