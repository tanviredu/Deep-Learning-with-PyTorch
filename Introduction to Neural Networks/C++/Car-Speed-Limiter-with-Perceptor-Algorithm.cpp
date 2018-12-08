#include <bits/stdc++.h>
using namespace std;

#define SPEED_LIMIT 60.00000000000000000
double limit;
double bias;
const double eps = 1e-3;
vector < pair < int , bool > > data;

bool prediction(double speed) {
	return speed < limit || (speed-limit)<eps;
}

void backpropagateLocal() {
	fstream input;
	input.open("./input.in",std::fstream::in | std::fstream::out | std::fstream::app);
	double speed, learn_rate=0.3;
	bool verdict;
	while(input >> speed >> verdict) {
		 bool y_hat = prediction(speed);
		 if(y_hat == verdict)
		 	continue;
		 else if(verdict == 1 && y_hat == 0)
		 	limit += speed*learn_rate;
		 else if(verdict == 0 && y_hat == 1)
		 	limit -= speed*learn_rate;
	
	}
}

void backpropagate() {
	double speed, learn_rate=0.3;
	bool verdict;
	for(auto x : data) {
		speed = x.first;
		verdict = x.second;
		 bool y_hat = prediction(speed);
		 if(y_hat == verdict)
		 	continue;
		 else if(verdict == 1 && y_hat == 0)
		 	limit += fabs(limit-speed)*learn_rate;
		 else if(verdict == 0 && y_hat == 1)
		 	limit -= fabs(limit-speed)*learn_rate;
	}
}

void perceptorAlgorithm() {
	backpropagate();
}

int main() {
//	freopen("output.txt","w",stdout);
	srand(time(0));
	fstream input;
	fstream out;
	input.open("./input.in",ios::out|ios::trunc);
	out.open("./output.out",ios::out|ios::trunc);
	double speed;
	limit = rand();
	int counter = 1;
//	backpropagateLocal();

	out << "Initial limit : " << fixed << setprecision(10) << limit << endl;
	int cnt = 1;
	while((out << "Pass " << counter++ << ":" << endl) &&
			 cnt++ < 1000 ) 
	{
		int s = rand() % 1800;
		speed = (double)s / 10.001;
		out << "Speed : " << speed << endl;
		bool verdict;
		perceptorAlgorithm();
//		backpropagateLocal();
		out << fixed << setprecision(9) << "new limit :" << limit << endl;
		if(prediction(speed)) {
			out << "Inside speed limit..Passed" << endl;
		}
		else {
			out << "Outside speed limit.Blocked" << endl;
		}
		verdict = (speed < SPEED_LIMIT || (speed-SPEED_LIMIT) < eps );
		out << "Verdict : ";
		if(verdict == prediction(speed))
			out << "Correct decision" << endl;
		else
			out << "Wrong decision" << endl;
		input << speed << " " << verdict << endl;
		data.push_back(make_pair(speed,verdict));
		out << endl;
	}
	cout << --(--cnt) << endl;
	input.close();
	out.close();
	return 0;
}
