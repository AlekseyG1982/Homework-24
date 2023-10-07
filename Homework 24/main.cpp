#include<iostream>
#include<ctime>
#include<cstdlib>

template<typename T> void fill_arr(T arr[], int const size, T left, T right)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (right - left) + left;
}
template<typename T> void print_arr(T arr[], int const size)
{
	std::cout << "{  ";
	for (int i = 0; i < size; i++) std::cout << arr[i] << "  ";
	std::cout << "}\n";
}
void resize_arr(int arr[], int const size, int n)
{
	int * new_arr = new int[size + n];
	for (int i = 0; i < size; i++)
		new_arr[i] = arr[i];
	for (int i = size; i < size + n; i++)
		new_arr[i] = rand()%11;
	print_arr(new_arr, size + n);
	arr = new_arr;
	
}


int main()
{
	std::cout << "Task 1.\n";
	int n = 5, m = 6;
	int sizeA=n, sizeB=m, sizeC = sizeA + sizeB;
	int* A = new int[sizeA];
	fill_arr(A, sizeA, 0, 10);
	print_arr(A, sizeA);

	int* B = new int[sizeB];
	fill_arr(B, sizeB, 0, 11);
	print_arr(B, sizeB);

	int* C = new int[sizeC];

	for (int i = 0; i < sizeA; i++)
		C[i] = A[i];
	for (int i = sizeA; i < sizeA + sizeB; i++)
		C[i] = B[i-sizeA];
	print_arr(C, sizeC);

	delete[] A;
	A = nullptr;
	delete[] B;
	B = nullptr;

	std::cout << "\nTask 2.\n";
	int size = 5, N=4;
	int* arr = new int [size];
	fill_arr(arr, size, 0, 11);
	print_arr(arr, size);

	resize_arr(arr, size, N);
	
	return 0;
}