#include <iostream>
using namespace std;

/*
quicksort 快排
*/

void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int key = arr[left];
		int i = left, j = right;
		while (i < j)
		{
			while (arr[j] > key && j > i)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (arr[i] < key && i < j)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = key;
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}
}

int main()
{
    int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 10;
		printf("%d ", a[i]);
	}
	printf("\n");
	quickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
