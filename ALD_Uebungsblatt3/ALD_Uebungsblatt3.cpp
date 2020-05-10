#include <iostream>
#include <string>
#include "datenstruktur.h"
#include "test.h"

// Test Code aktivieren/deaktivieren
#define DEBUG 1

using namespace std;
// main function
int main()
{
	searchTree t;
	if (DEBUG == 1) {
		for (int i = 0; i < 15; i++) {
			t.insertNode(t.root, rand() % 10);
		}

		//print constructed binary tree
		t.printTree(t.root, nullptr, false);

		// In order (lnr) algorithm:
		t.inOrder(t.root);

		//check if tree contains value
		int input;
		cout << "\nValue to search for:" << endl;
		cin >> input;
		if (t.containsNode(t.root, input)) {
			cout << "node with specific value has been found!\n" << endl;
		}
		else {
			printf("couldn't find specific value in nodes..\n");
		}
	}

	// Testtreiber
	/*
	Runtime tests for random order insertion:
	-> Runtime for 2^12 values: 0.005
	-> Runtime for 2^13 values: 0.01
	-> Runtime for 2^14 values: 0.022
	-> Runtime for 2^15 values: 0.05
	-> Runtime for 2^16 values: 0.116

	Runtime tests for ascending order insertion:
	-> Runtime for 2^12 values: 0.364
	-> Runtime for 2^13 values: 0.735
	-> Runtime for 2^14 values: 1.466
	-> Runtime for 2^15 values: 2.937
	-> Runtime for 2^16 values: 5.943
	-> Runtime for 2^17 values: 11.906
	*/
	messung1();
	messung2();

	return 0;
}