#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
#include <chrono>

using namespace std;
int main()
{
	int arrlength;
	int bogoarrlength;
	int value;

	arrlength = 30;
	bogoarrlength = 10;

	Array arr(arrlength);
	Array Bogoarr(bogoarrlength);
	Char_Array arrC(arrlength);
	int test_arr[30] = { 7, 3, 2, 7, 3, 8, 2, 4, 8, 1, 4, 8, 1, 0, 8, 3, 7, 6, 3, 8, 9, 2, 1, 3, 1, 0, 8, 0, 7, 0 };
	int bogo_arr[10] = {1,3,5,7,2,5,3,2,1,8};

	cout << "array before sorting - ";
	for (int i = 0; i < arrlength; i++)
	{
		cout << test_arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < arrlength; i++)
	{
		arr.filling(i, test_arr[i]);
	}

	arr.quicksort(0, 29);

	cout << "array after QuickSort - ";

	for (int i = 0; i < arrlength; i++)
	{
		cout << arr.getValue(i) << " ";
	}
	cout << endl;
	cout << endl;

	cout << "array before sorting - ";
	for (int i = 0; i < bogoarrlength; i++)
	{
		cout << bogo_arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < bogoarrlength; i++)
	{
		Bogoarr.filling(i, bogo_arr[i]);
	}

	Bogoarr.BogoSort();

	cout << "array after BogoSort - ";

	for (int i = 0; i < bogoarrlength; i++)
	{
		cout << Bogoarr.getValue(i) << " ";
	}
	cout << endl;
	cout << endl;

	cout << "array before sorting - ";
	for (int i = 0; i < arrlength; i++)
	{
		cout << test_arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < arrlength; i++)
	{
		arr.filling(i, test_arr[i]);
	}

	arr.BubbleSort();

	cout << "array after BubbleSort - ";

	for (int i = 0; i < arrlength; i++)
	{
		cout << arr.getValue(i) << " ";
	}
	cout << endl;
	cout << endl;

	arr.BinarySearch(4);

	cout << endl;
	cout << endl;

	for (int i = 0; i < arrlength; i++)
	{
		arrC.filling(i, test_arr[i] + '0');
	}

	arrC.CountingSort();

	cout << "array after CountingSort - ";

	for (int i = 0; i < arrlength; i++)
	{
		cout << arrC.getValue(i) << " ";
	}
	cout << endl;
	cout << endl;
}