#include "ofApp.h"
//#pragma comment(linker,"/subsystem:\"Windows\" /entry:\"mainCRTStartup\"")
//--------------------------------------------------------------

double g(double* k, size_t dim, void* params)
{
	double A = 1.0 / (PI * PI * PI);
	return A / (1.0 - cos(k[0]) * cos(k[1]) * cos(k[2]));

}

void ofApp::setup(){
	//setIcon("data//icon.ico");

	double xl[3] = { 0, 0, 0 };
	double xu[3] = { M_PI, M_PI, M_PI };

	const gsl_rng_type* T;
	gsl_rng* r;

	gsl_monte_function G = { &g, 3, 0 };

	size_t calls = 500000;

	gsl_rng_env_setup();

	T = gsl_rng_default;
	r = gsl_rng_alloc(T);

	monteVegasIntegrate(&G, xl, xu, r, 3, 10000);
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

void ofApp::monteVegasIntegrate(gsl_monte_function* f, double xLower[], double xUpper[], gsl_rng* range, int dimensions, int numCalls)
{


	double res, err;

	gsl_monte_vegas_state* s = gsl_monte_vegas_alloc(dimensions);

	gsl_monte_vegas_integrate(f, xLower, xUpper, dimensions, numCalls, range, s, &res, &err);
	cout << "vegas warm-up" << res << " " << err << endl;

	do
	{
		gsl_monte_vegas_integrate(f, xLower, xUpper, dimensions, numCalls / 5, range, s, &res, &err);
		cout << "result = " << res << " err = " << err << " chisq = " << gsl_monte_vegas_chisq(s) << endl;
	} while (fabs(gsl_monte_vegas_chisq(s) - 1.0) > 0.5);

	cout << "vegas final : result " << res << " error " << err << endl;

	gsl_monte_vegas_free(s);

}
