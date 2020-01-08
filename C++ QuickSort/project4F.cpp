/*
-HW #4
-Luke Landon
-Visual Studio
ID # 200129064
*/
#include<iostream>

using namespace std;
//swap array accepts two pinters and swithces the values inside
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/*
The funcion is to switch the arrangment of elements in the array to go from smallest
to largest by using a pivot on the furthest right of the array.
The parameters of this method is to pass an array and the highest and lowest integer of the array.
This is to give the sorting algoritham a starting and ending point at which to sort from.
*/
int partition(int arr[], int low, int high)
{
	//creates the pivot on the furthest right of the array position 0
	int pivot = arr[low];
	//sets the q and i variables to one position above the pivot 
	int q = low+1;
	int i = low+1;

	//while loop compares if i is less then the the end of the array if so loops through and incraments each time
	//this will happen untill it hits the end of the array
	while (i <= high) {
		//if loop compares the array value of i to that of the pivot in position 0
		//uf it is less it will call on swap method to change the position of the elements in the array
		//then will incriment q to to the next value
		if (arr[i] <= pivot) {
			swap(arr[q], arr[i]);
			q++;
			}
		++i;
	}
	//after the whole array is done will swap q-1 with the low value of the array.
		swap(arr[low], arr[q-1]);
		//return will return the q -1
		return q-1;
}

//quicksort will pass will use a recusion to continue to loop and break apart the array until all elements are sorted
void quickSort(int arr[], int low, int high)
{
	//compares if low is less then high if so will continue to loop through and compare in parition method 
	//after this is done will split quicksort and continue to loop though partiion again
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
//prints the array by passing in the array and the size of it 
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
//main sets the array and value needed to sort
//calls on the quicksort method and then uses printArray to print out the sorted array.
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: " << endl;
	printArray(arr, n);
	return 0;
}