#include<stdio.h>
void Swap(int* A, int* B);
void PrintArr(int* arr, const int arrsize);

void SelectionSort(int* arr, const int arrsize);
void BubleSort(int* arr, const int arrsize);
int main() {
	const int Asize = 6;
	int A[6] = { 3,1,5,7,9,6 };
	PrintArr(A,Asize);
	BubleSort(A, Asize);
	PrintArr(A, Asize);
	while (1) {

	}
	return 0;
}

void Swap(int* A, int* B) {
	int tmp = *A;
	*A = *B;
	*B = tmp;
}
void PrintArr(int* arr, const int arrsize) {
	for (int i = 0; i < arrsize; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void SelectionSort(int* arr, const int arrsize) {
	int maxindex = 0;
	int max = 0;
	for (int i = arrsize - 1; i >= 0; i--) {
		max = arr[0];
		maxindex = 0;
		for (int j = 0; j <= i; j++) {
			if (arr[j] > max) {
				max = arr[j];
				maxindex = j;
			}
		}
		Swap(&arr[i], &arr[maxindex]);
	}
}
void BubleSort(int* arr, const int arrsize) {
	char sorted = 1;
	for (int i = arrsize - 1; i >= 0; i--) {
		sorted = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				sorted = 0;
				Swap(&arr[j], &arr[j + 1]);
			}
		}
		if (!sorted) {
			break;
		}
	}
}
void insertionSort(int* arr, const int arrsize) {

}
