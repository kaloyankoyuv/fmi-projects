#include <iostream>

double countHW(char *schedule) {

	int i = 0;
	double result = 0;

	while(schedule[i] != 0) {
		if(schedule[i]=='w') {
			result++;
		}
		i++;
	}

	return result;

}

double countST(char *schedule) {

	int i = 0;
	double result = 0;

	while(schedule[i] != 0) {
		if(schedule[i]=='s') {
			result++;
		}
		i++;
	}

	return result;

}

int main() {


	int numberOfDays = 5;

	double N;
	std::cin >> N;

	double hoursInvested = 0;

	char schedule[255];

	while(numberOfDays--) {
		std::cin >> schedule;
		hoursInvested += countHW(schedule) + countST(schedule)/2;
	}

	if(hoursInvested >= N) {
		std::cout << "You got it!" << std::endl;
	} else {
		std::cout << "You should work more" << std::endl;
	}

	return 0;
}
