#include <iostream>
#include "the_double_hashing.h"
#include "the_quadratic_probing.h"

using namespace std;

//Our main function that makes teminations 
//and handles the switch between quadratic 
//probing and double hashing

int main()
{
	int bit;
	char exit;
	bool terminate = false;

	the_quadratic_probing qp;
	the_double_hashing dh;

	//handles initial menu

	while (!terminate) {
		
		cout << "Make a choice between Quadratic Hashing (1) and Double Hashing (2) to proceed... " << endl;
		cin >> bit;

		if (bit == 1) {
			qp.QuadraticSeq();
		}
		else {
			dh.DoubleSeq();
		}

		cout << "Press (q) to quit otherwise press any key to start again..." << endl;
		cin >> exit;
		
		if (exit == 'q')
			terminate = true;
	}
}