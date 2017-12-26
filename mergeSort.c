#include <stdio.h>
#include <stdlib.h>

// Uses merge sort algorithm to sort list
void mergeSort(int list[], int beg, int end);
void merge(int list[], int beg, int mid, int end);
void printList(int list[], int size);

int main()
{
	// Values  to be sorted
	int list[] = {5,4, 3, 21, 12, 27};
	// List size from 1 to n, not 0 to n.
	int listSize = sizeof(list)/sizeof(list[0]);
	printList(list,listSize);
	
	// MergeSort algorithm on list
	mergeSort(list,0,listSize - 1);
	printList(list,listSize);
	
	return 0;
}
// mergeSort halfs the list reursivly and then merges
void mergeSort(int list[], int beg, int end)
{
	if (beg < end)
	{
		int mid = (beg+end)/2;
		
		mergeSort(list, beg, mid);
		mergeSort(list, mid + 1, end);
		
		// Once list is halfed to only 1 index, start merging 
		merge(list, beg, mid, end);
	}
}
// Merges left and right lists moving the lesser of 
//value of the two to the left
void merge(int list[], int beg, int mid, int end)
{
	int n1 = mid - beg + 1;// Size of left size of the list
	int n2 = end - mid;//  Size  or right size of the list
	
	int L[n1], R[n2];// Make array to hold left and right split
	int i, j, z;
	// Move left list values to left array
	for (i = 0; i < n1;++i)
		L[i] = list[beg + i];
	// Move right list values to right array
	for (j = 0; j < n2;++j)
		R[j] = list[mid + j + 1];
	
	z = beg;// Z is the current index, start from left moves to the right
	i = 0;
	j = 0;
	//  Walks through the left and right half of the list
	while (i < n1 && j < n2)
	{
		// If Left index element is less than the right move the 
		// left element to the appropriate list index 
		if (L[i] <= R[j])
		{
			list[z] = L[i];
			i++;
		}	
		else
		{
			list[z] = R[j];
			j++;
		}
		z++;// Moves the index value in list
	}
	// Copy the last bit of data in L[] into list[]
	while (i < n1)
	{
		list[z] = L[i];
		i++;
		z++;
	} 
	// Copy the last bit of data in L[] into list[]
	while (j < n2)
	{
		list[z] = R[j];
		j++;
		z++;
	}
}
// Prints a list array
void printList(int list[], int size)
{
	for (int i = 0; i < size;++i)
		printf("%d ", list[i]);
	printf("\n");
}
