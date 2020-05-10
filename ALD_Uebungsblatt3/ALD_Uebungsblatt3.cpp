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
	messung1();
	messung2();

	return 0;
}