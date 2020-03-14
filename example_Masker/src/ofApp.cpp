#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //ofSetLogLevel( OF_LOG_VERBOSE );
	
	ofEnableArbTex();//restores normal OF mode

	ofBackground(0);

    bDrawGui = true;
    bDisplayFps = true;
    mode = 1;
    
	img.load( "scope.png");

	//-

    fbo.allocate( 640, 480 );

	frag1.allocate(fbo);
	frag2.allocate(fbo);
	frag3.allocate(fbo);
    
	//-

	gui.setup("", "setting.xml");
    gui.setName( "GUI" );
	gui.add(bReset);
	gui.add(frag1.parameters);
	gui.add(frag2.parameters);
	gui.add(frag3.parameters);

	listener = bReset.newListener([this](bool&) {this->Changed_bReset(); });
}

//--------------------------------------------------------------
void ofApp::Changed_bReset() {
	ofLog() << "bReset: "<<(bReset?"ON":"OFF");

	if (bReset)
	{
		bReset = false;

		frag1.active = true;
		frag1.low = 0;
		frag1.high = 1;

		frag2.active = true;
		frag2.hue = 0;
		frag2.brightness = 0;
		frag2.saturation = 1;
		frag2.contrast = 1;

		frag3.active = false;
		frag3.speed = 1;
		frag3.pulse = 1;
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	ofDisableArbTex();//required the reallocate

	if( bDrawGui ){
		fbo.allocate( ofGetWidth(), ofGetHeight()-220 );
		gui.setPosition(1700, 10 );
	}else{
		fbo.allocate( ofGetWidth(), ofGetHeight() );
	}

	ofEnableArbTex();//restores normal OF mode
}

//--------------------------------------------------------------
void ofApp::update(){

    switch (mode) {

		//image
        case 1:
            fbo.begin();
                ofClear(0,0,0,0);
                img.draw(0,0);
            fbo.end();

			frag1.apply(fbo);
			frag2.apply(fbo);
			frag3.apply(fbo);
        break;

		//lines
        case 2:
        {
            fbo.begin();
                ofClear(0,0,0,0);
                ofSetLineWidth(3.0f);

                static const float nOffset = 0.3f;
                static const int points = 3;
                nCursor += 0.0007;
                
                //ofFill();
                ofNoFill();
                ofSetColor(255, 80, 80 );
                for( int k=0; k<3; ++k){
                    /*
                    switch( k ){
                        case 0: ofSetColor( 255, 0, 0, 245 ); break;
                        case 1: ofSetColor( 0, 255, 0, 245 ); break;
                        case 2: ofSetColor( 0, 0, 255, 245 ); break;
                    }
                    */ 
                    ofBeginShape();
                    for(int i=0; i<points; ++i){
                        int x = ofNoise((k*points+i)*nOffset, nCursor)*fbo.getWidth();
                        int y = ofNoise((k*points+i)*2.0f*nOffset, nCursor)*fbo.getHeight();
                        ofVertex( x, y );
                    }
                    ofEndShape(true);
                }
                /*
                ofNoFill();
                ofSetColor(255);
                for( int k=0; k<3; ++k){
                    ofBeginShape();
                    for(int i=0; i<points; ++i){
                        int x = ofNoise((k*points+i)*nOffset, nCursor)*fbo.getWidth();
                        int y = ofNoise((k*points+i)*2.0f*nOffset, nCursor)*fbo.getHeight();
                        ofDrawBitmapString("vertex " + ofToString(i), x, y );
                        ofVertex( x, y );
                    }
                    ofEndShape(true);
                }
                */ 
            fbo.end();

			frag1.apply(fbo);
			frag2.apply(fbo);
			frag3.apply(fbo);
        }
        break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw( 0, 0 );
	//frag.draw( 0, 0 );

	if(bDrawGui) gui.draw();

	ofSetColor(255);
	if(bDisplayFps) ofDrawBitmapString( "fps="+ofToString(ofGetFrameRate()), 20, ofGetHeight()-20 );

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch( key ){
		case '1': mode = 1; break;
		case '2': mode = 2; break;
		case '0': mode = 0; break;
		case 'g': bDrawGui = !bDrawGui;	break;
		case ' ': frag1.active = true; break;
		case 'r': frag1.reload(); break;
		case 'f': bDisplayFps = !bDisplayFps; break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if( key == ' ' ) frag1.active = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
