
#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define maxn 100

using namespace std;
void sort(int*, int);
void merge(int*, int, int);
void vstavkamiSort(int*, int);
void quickSort(int[], int, int);
void countingSort(int*, int);
int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");


	int* sorted_array;
	int* temparr;
	int* c;
	int d;
	bool While1 = true;
	int size;
	cout << "1.случайные целые числа 2^8" << endl;
	cout << "2.случайные целые числа 2^17" << endl;
	cout << "3.почти упорядоченный массив" << endl;
	cout << "4.массив с маленьким разбросом выборки" << endl;
	cout << "выбирите вариант " << endl;
	cin >> d;

	switch (d)
	{

	case 1:
		size = 256;
		sorted_array = new int[size];
		temparr = new int[size];
		for (int counter = 0; counter < size; counter++)
		{
			sorted_array[counter] = rand() % 100000;
		}
		cout << endl;
		break;
	case 2:
		size = 131072;
		sorted_array = new int[size];
		temparr = new int[size];
		break;
		for (int counter = 0; counter < size; counter++)
		{
			sorted_array[counter] = rand() % 100000;
		}
		cout << endl;
	case 4:
		size = 131072;
		sorted_array = new int[size];
		temparr = new int[size];
		break;
		for (int counter = 0; counter < size; counter++)
		{
			sorted_array[counter] = rand() % 20;
		}
		cout << endl;

		break;
	default:
		size = 256;
		sorted_array = new int[size];
		temparr = new int[size];
		for (int counter = 0; counter < size; counter++)
		{
			sorted_array[counter] = rand() % 100000;
		}
		break;
	}
	int a;
	bool While = true;
	while (While) {
		cout << "1.сортировка вставками  " << endl;
		cout << "2.сортировка слиянием" << endl;
		cout << "3.сортировка пузырьком" << endl;
		cout << "4.сортировка quick sort" << endl;
		cout << "5.сортировка подсчетом" << endl;
		cout << "6.сортировка гибридная" << endl;
		cout << "введите вариант " << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "сортировка вставками" << endl;
			for (int i = 0; i < size; i++)temparr[i] = sorted_array[i];
			vstavkamiSort(temparr, size);
			for (int i = 0; i < size; i++)cout << temparr[i] << " ";
			cout << endl;

			break;
		case 2:
			cout << "сортировка слиянием" << endl;
			for (int i = 0; i < size; i++)temparr[i] = sorted_array[i];
			merge(temparr, 0, size - 1);
			for (int i = 0; i < size; i++)cout << temparr[i] << " ";
			cout << endl;

			break;
		case 3:
			cout << "сортировка пузырьком" << endl;

			for (int i = 0; i < size; i++)temparr[i] = sorted_array[i];
			sort(temparr, size);
			for (int i = 0; i < size; i++)cout << temparr[i] << " ";
			cout << endl;

			break;
		case 4:
			cout << "сортировка quick sort" << endl;

			for (int i = 0; i < size; i++)temparr[i] = sorted_array[i];
			quickSort(temparr, 0, size - 1);
			for (int i = 0; i < size; i++)cout << temparr[i] << " ";
			cout << endl;

			break;
		case 5:
			cout << "сортировка подсчетом" << endl;
			for (int i = 0; i < size; i++)temparr[i] = sorted_array[i];
			countingSort(temparr, size);
			for (int i = 0; i < size; i++)cout << temparr[i] << " ";
			cout << endl;

			break;
		case 6:

			While = false;

			break;
		default:
			cout << "error\n";
			While = false;
			break;
		}
	}
	return 0;

	for (int counter = 0; counter < size; counter++)
	{
		cout << sorted_array[counter] << "  ";
	}
	cout << endl;
	delete[] sorted_array;
	system("pause");
	return 0;
}

void vstavkamiSort(int* arrayPtr, int length)
{
	int temp,
		item;
	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter];
		item = counter - 1;
		while (item >= 0 && arrayPtr[item] > temp)
		{
			arrayPtr[item + 1] = arrayPtr[item];
			arrayPtr[item] = temp;
			item--;
		}
	}
}

void merge(int* a, int l, int r) {
	if (r == l)
		return;
	if (r - l == 1) {
		if (a[r] < a[l])
			swap(a[r], a[l]);
		return;
	}
	int m = (r + l) / 2;
	merge(a, l, m);
	merge(a, m + 1, r);
	int buf[maxn];
	int xl = l;
	int xr = m + 1;
	int cur = 0;
	while (r - l + 1 != cur) {
		if (xl > m)
			buf[cur++] = a[xr++];
		else if (xr > r)
			buf[cur++] = a[xl++];
		else if (a[xl] > a[xr])
			buf[cur++] = a[xr++];
		else buf[cur++] = a[xl++];

	}
	for (int i = 0; i < cur; i++)
		a[i + l] = buf[i];
}


void sort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] > a[j])swap(a[i], a[j]);
		}
	}
}
void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];


	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};


	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

void countingSort(int a[], int n)
{
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int* c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i] - min] = c[a[i] - min] + 1;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			a[i] = j;
			c[j - min]--;
			i++;
		}
	}
}
