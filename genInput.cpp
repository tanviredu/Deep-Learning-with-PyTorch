#include <bits/stdc++.h>
using namespace std;

int main() {
	fstream input;
	input.open("input.in" , std::fstream::in | std::fstream::out | std::fstream::app);

	double speed;
	
	for(int i = 1; i <= 10000; ++i) {
		speed = (double)rand();
		speed = (double)fmod(speed,180.0);

		bool verdict = speed<60.0;
	//	input << speed << " " << verdict << endl;
	}
	input.close();
}