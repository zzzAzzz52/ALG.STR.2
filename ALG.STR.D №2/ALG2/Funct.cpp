#include "Header.h"
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;

void Array::filling(int index, int value) //Filling of the array
{
	array[index] = value;
}

void Char_Array::filling(int index, char value) //Filling of the char array
{
	array[index] = value;
}

int Array::getValue(int index) //Getting the value of array
{
	return array[index];
}

char Char_Array::getValue(int index) //Getting the value of char array
{
	return array[index];
}

int Array::correct()  //Part of bogoSort
{
	int length2 = length;
	while (--length2 > 0)
		if (array[length2 - 1] > array[length2])
			return 0;
	return 1;
}

void Array::shuffle() //Part of bogoSort
{
	for (int i = 0; i < length; ++i)
		swap(array[i], array[(rand() % length)]);
}

void Array::BogoSort()
{
	while (!correct())
		shuffle();
}

void Array::quicksort(int first, int last) //quicksort
{
	int mid, count;
	int f = first, l = last;
	mid = array[(f + l) / 2];
	do
	{
		while (array[f] < mid) f++;
		while (array[l] > mid) l--;
		if (f <= l)
		{
			count = array[f];
			array[f] = array[l];
			array[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(first, l);
	if (f < last) quicksort(f, last);
}

void Array::BubbleSort() //BubbleSort
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void Array::BinarySearch(int key) //BinarySearch
{
	bool flag = false;
	int l = 0;
	int r = length - 1;
	int mid;
	while ((l <= r) && (flag != true))
	{
		mid = (l + r) / 2;
		if (array[mid] == key) flag = true;
		if (array[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	if (flag) cout << "Index of element " << key << " in array is equal to: " << mid;
	else cout << "Sorry, but there is no such an element in array";
}

void Char_Array::CountingSort() //Counting sort
{
	int* output = new int[length];
	int* count = new int[length];
	int max = 0;
	int tmp = 0;
	int tmp2 = 0;
	int tmp3 = 0;

	// Find the largest element of the array
	for (int i = 1; i < length; i++) 
	{
		tmp = array[i] - '0';
		if (tmp > max)
		{
			max = tmp;
		}
	}

	// Initialize count array with all zeros.
	for (int i = 0; i <= max; ++i) 
	{
		count[i] = 0;
	}

	// Store the count of each element
	for (int i = 0; i < length; i++) 
	{
		count[array[i] - '0']++;
	}

	// Store the cummulative count of each array
	for (int i = 1; i <= max; i++) 
	{
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (int i = length - 1; i >= 0; i--) 
	{
		output[count[array[i] - '0'] - 1] = array[i] - '0';
		count[array[i] - '0']--;
	}

	// Copy the sorted elements into original array
	for (int i = 0; i < length; i++)
	{
		array[i] = output[i] + '0';
	}

	delete[] output;
	delete[] count;

}