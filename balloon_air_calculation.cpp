#include <iostream>
#include <string>
#define PI 3.14159
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

	float balloonRadius, balloonVolume, balloonMass;
	float emptyBalloonWeight;
	float fullBalloonWeight = 15.5;

	cout << "Write the radius of the balloon: ";
	cin >> balloonRadius;

	balloonVolume = ( 4  * PI * pow(balloonRadius, 3) ) / 3;
	cout << "The balloon volume is " << balloonVolume << endl;

	cout << "Write the balloon weight without the air: ";
	cin >> emptyBalloonWeight;

	balloonMass = fullBalloonWeight - emptyBalloonWeight;
	cout << "The balloon mass is " << balloonMass;

	return 0;
}
