#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "datenstruktur.h"

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void messung2() {
	searchTree n;
	std::cout << "\nRuntime tests for ascending order insertion:" << std::endl;

	for (int i = 12; i <= 17; i++)
	{
		int number = pow(2, i);

		int* arrVal = (int*)malloc(sizeof(int) * number);
		for (int i = 0; i < number; i++)
		{
			arrVal[i] = rand();
		}
		// ascending order using Quicksort library
		qsort(arrVal, number, sizeof(int), compare);

		clock_t t1 = clock();
		std::cout << "-> Runtime for 2^" << i << " values: ";
		for (int i = 0; i < number; i++)
		{
			n.insertNode(n.root, arrVal[i]);
		}
		clock_t t2 = clock();
		float t3 = (float)(t2 - t1) / (float)CLOCKS_PER_SEC;
		std::cout << t3 << std::endl;
	}

	//n.printTree(n.root, nullptr, false);
}

void messung1() {
	searchTree n;
	std::cout << "\nRuntime tests for random order insertion:" << std::endl;
	for (int i = 12; i < 17; i++)
	{
		clock_t t1 = clock();
		int number = pow(2, i);
		std::cout << "-> Runtime for 2^" << i << " values: ";
		for (int i = 0; i < number; i++)
		{
			int randnr = rand();
			n.insertNode(n.root, randnr);
		}
		clock_t t2 = clock();
		float t3 = (float)(t2 - t1) / (float)CLOCKS_PER_SEC;
		std::cout << t3 << std::endl;
	}

	//n.printTree(n.root, nullptr, false);
}