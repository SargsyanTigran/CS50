#include <iostream>
#include <time.h>

using namespace std;

void create_array(int size, int array[]);
void bubble_sort(int size, int array[]);
void insertion_sort(int size, int array[]);
void selection_sort(int size, int array[]);
void merge(int array[], int start, int middle, int end);
void merge_sort(int array[], int start, int end);
void quick_sort(int array[], int start, int end);
int partition(int array[], int start, int end);

int main(){
	int size1 = 10000;
	int size2 = 50000;
	int size3 = 100000;

	int array1[size1];
	int array2[size2];
	int array3[size3];

	clock_t bubble1_start = clock();
	create_array(size1, array1);
	bubble_sort(size1, array1);
	clock_t bubble1_end = clock();
	double bubble1 = double(bubble1_end - bubble1_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with bubble sort with %i elements %.6f seconds.\n", size1,  bubble1);

	clock_t bubble2_start = clock();
	create_array(size2, array2);
	bubble_sort(size2, array2);
	clock_t bubble2_end = clock();
	double bubble2 = double(bubble2_end - bubble1_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with bubble sort with %i elements %.6f seconds.\n", size2,  bubble2);

	clock_t bubble3_start = clock();
	create_array(size3, array3);
	bubble_sort(size3, array3);
	clock_t bubble3_end = clock();
	double bubble3 = double(bubble3_end - bubble3_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with bubble sort with %i elements %.6f seconds.\n", size3,  bubble3);

	clock_t insertion1_start = clock();
	create_array(size1, array1);
	insertion_sort(size1, array1);
	clock_t insertion1_end = clock();
	double insertion1 = double(insertion1_end - insertion1_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with insertion sort with %i elements %.6f seconds.\n", size1,  insertion1);

	clock_t insertion2_start = clock();
	create_array(size2, array2);
	insertion_sort(size2, array2);
	clock_t insertion2_end = clock();
	double insertion2 = double(insertion2_end - insertion2_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with insertion sort with %i elements %.6f seconds.\n", size2,  insertion2);

	clock_t insertion3_start = clock();
	create_array(size3, array3);
	insertion_sort(size3, array3);
	clock_t insertion3_end = clock();
	double insertion3 = double(insertion3_end - insertion3_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with insertion sort with %i elements %.6f seconds.\n", size3,  insertion3);

	clock_t selection1_start = clock();
	create_array(size1, array1);
	selection_sort(size1, array1);
	clock_t selection1_end = clock();
	double selection1 = double(selection1_end - selection1_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with selection sort with %i elements %.6f seconds.\n", size1,  selection1);

	clock_t selection2_start = clock();
	create_array(size2, array2);
	selection_sort(size2, array2);
	clock_t selection2_end = clock();
	double selection2 = double(selection2_end - selection2_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with selection sort with %i elements %.6f seconds.\n", size2,  selection2);

	clock_t selection3_start = clock();
	create_array(size3, array3);
	selection_sort(size3, array3);
	clock_t selection3_end = clock();
	double selection3 = double(selection3_end - selection3_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with selection sort with %i elements %.6f seconds.\n", size3,  selection3);

	clock_t merge1_start = clock();
	create_array(size1, array1);
	merge_sort(array1, 0, size1 -1);
	clock_t merge1_end = clock();
	double merge1 = double(merge1_end - merge1_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with merge sort with %i elements %.6f seconds.\n", size1,  merge1);

	clock_t merge2_start = clock();
	create_array(size2, array2);
	merge_sort(array2, 0, size2 -1);
	clock_t merge2_end = clock();
	double merge2 = double(merge2_end - merge2_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with merge sort with %i elements %.6f seconds.\n", size2,  merge2);

	clock_t merge3_start = clock();
	create_array(size3, array3);
	merge_sort(array3, 0, size3 -1);
	clock_t merge3_end = clock();
	double merge3 = double(merge3_end - merge3_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with merge sort with %i elements %.6f seconds.\n", size3,  merge3);

	clock_t quick1_start = clock();
	create_array(size1, array1);
	quick_sort(array1, 0, size1 - 1 );
	clock_t quick1_end = clock();
	double quick1 = double(quick1_end - quick1_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with quick sort with %i elements %.6f seconds.\n", size1,  quick1);

	clock_t quick2_start = clock();
	create_array(size2, array2);
	quick_sort(array2, 0, size2 - 1 );
	clock_t quick2_end = clock();
	double quick2 = double(quick2_end - quick2_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with quick sort with %i elements %.6f seconds.\n", size2,  quick2);

	clock_t quick3_start = clock();
	create_array(size3, array3);
	quick_sort(array3, 0, size3 - 1 );
	clock_t quick3_end = clock();
	double quick3 = double(quick3_end - quick3_start)/CLOCKS_PER_SEC;
	printf("Time spent to sort array with quick sort with %i elements %.6f seconds.\n", size3,  quick3);
}

void create_array(int size, int array[]){
	for(int i = 0; i < size; i++){
		array[i] = rand() % 1000;
	}
}

void bubble_sort(int size, int array[]){
	for(int i = 0; i < size; i++){
		for(int j = i + 1; j < size; j++){
			if(array[j] < array[i]){
				int change = array[i];
				array[i] = array[j];
				array[j] = change;
			}
		}
	}
}

void insertion_sort(int size, int array[]){
	for(int i = 1; i < size; i++){
		int j = i-1;
		int k = array[i];

		while(array[j] > k && j >= 0){
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = k;
	}
}

void selection_sort(int size, int array[]){
	for(int i = 0; i < size; i++){
		int min = i;
		for(int j = i+1; j < size; j++){
			if(array[j] < array[min])
				min = j;
		}
		if(min != i){
			int change = array[i];
			array[i] = array[min];
			array[min] = change;
		}
	}
}

void merge(int array[], int start, int middle, int end) {

	int n1 = middle - start + 1;
	int n2 = end - middle;

	int left[n1], right[n2];

	for (int i = 0; i < n1; i++)
		left[i] = array[start + i];
	for (int j = 0; j < n2; j++)
		right[j] = array[middle + 1 + j];

	int i, j, k;
	i = 0;
	j = 0;
	k = start;

	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		array[k] = right[j];
		j++;
		k++;
	}
}

void merge_sort(int array[], int start, int end) {
	if (start < end) {
		int middle = start + (end - start) / 2;

		merge_sort(array, start, middle);
		merge_sort(array, middle + 1, end);

		merge(array, start, middle, end);
	}
}

int partition(int array[], int start, int end)
{

	int piv = array[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (array[i] <= piv)
			count++;
	}

	int piv_idx = start + count;
	swap(array[piv_idx], array[start]);

	int i = start, j = end;

	while (i < piv_idx && j > piv_idx) {

		while (array[i] <= piv) {
			i++;
		}

		while (array[j] > piv) {
			j--;
		}

		if (i < piv_idx && j > piv_idx) {
			swap(array[i++], array[j--]);
		}
	}

	return piv_idx;
}

void quick_sort(int array[], int start, int end)
{

	if (start >= end)
		return;
	int part = partition(array, start, end);

	quick_sort(array, start, part - 1);
	quick_sort(array, part + 1, end);
}
