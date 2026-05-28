#include "ofApp.h"
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_vector.h>
//#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"")
//--------------------------------------------------------------
void ofApp::setup(){
	//setIcon("data//icon.ico");
	//double x = 5.0;
	//double y = gsl_sf_bessel_J0(x);
	//printf("J0(%g) = %.18e\n", x, y);
	int i;
	gsl_vector* v = gsl_vector_alloc(10);
	for (i = 0; i < 10; i++)
	{
		gsl_vector_set(v, i, 1.23 + i);
	}
	for (i = 0; i < 10; i++)
	{
		printf("v_%d = %g\n", i, gsl_vector_get(v, i));
	}
	gsl_vector_free(v);
	getchar();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::exit(){
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
