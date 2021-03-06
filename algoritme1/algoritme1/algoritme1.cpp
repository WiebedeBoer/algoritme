// algoritme1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Implement a (sorting) algorithm of choice in C++. Measure the execution time of the algorithm using different input sizes and perform a regression analysis.

//On blackboard you’ll find a document describing how to do a regression analysis in Excel, 
//but you’re free to use other tools, such as R or SPSS.
//Do the results of your analysis match what Wikipedia says about the order of the algorithm ?

#include "pch.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

/*
//swap bubble sort
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
*/

/*
//function to print an array 
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("n");
}

// A function to implement bubble sort , should be O(n^2)
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
*/

using namespace std;

void bubbleSort(vector<int>& a);

void printVector(vector<int> a);

int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;
	
	//int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	//int arr[] = { 64, 34, 25, 12, 22, 11, 90,10,20,13 };
	//int Rand = (rand() % 100) + 1;
	//int arr[] = {};
	//int arr[] = { 64, 34, 25, 12, 22, 11, 90,10,20,13,45,55,53,66,99,63,98,95 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//bubbleSort(arr, n);
	//printf("Sorted : \n");

	//vector<int> a{ 3,2,6,1 };
	//vector<int> a{ 64, 34, 25, 12, 22, 11, 90, 10, 20, 13, 45, 55, 53, 66, 99, 63, 98, 95 };
	int size = 5;
	vector<int> a(size);
	/*
	a[0] = 64;
	a[1] = 34;
	a[2] = 25;
	a[3] = 22;
	a[4] = 25;
	*/
	for (int j = 0; j < size; j++) {
		int Rand = (rand() % 10000) + 1;
		//a[i] = Rand;
		a.push_back(Rand);

		printVector(a);
		bubbleSort(a);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << elapsed_seconds.count() << std::endl; //print elapsed time
	}



	//printArray(arr, n);

	return 0;
}

void bubbleSort(vector<int>& a)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < a.size() - 1; i++) {
			if (a[i] > a[i + 1]) {
				a[i] += a[i + 1];
				a[i + 1] = a[i] - a[i + 1];
				a[i] -= a[i + 1];
				swapp = true;
			}
		}
	}
}

void printVector(vector<int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " ";

	}
	cout << endl;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
