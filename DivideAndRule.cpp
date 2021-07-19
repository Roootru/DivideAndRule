#include <iostream>

int dar_Sum(int *arr, int size_arr)
{
	if (size_arr == 0)
		return 0;
	return ((*arr) + dar_Sum(arr + 1, size_arr - 1));
}

int dar_CountOfArray(int* arr)
{
	return 0;
}

int dar_FindMaxOfArray(int* arr, int size_arr)
{
	if (size_arr == 0)
		return 0;
	int sub_max = dar_FindMaxOfArray(arr + 1, size_arr - 1);
	if (sub_max > *arr)
		return sub_max;
	else
		return *arr;
	
	/*if (size_arr != 0)
	{
		if ((*arr) > MAX)
			MAX = *arr;
		dar_FindMaxOfArray(arr + 1, size_arr - 1, MAX);
	}*/
}

void dar_QSortOfArray(int* arr, int size)
{
	int left = 0;
	int right = size - 1;
	int mid = (left + right) / 2;

	do
	{
		while (arr[left] < arr[mid])
		{
			left++;
		}
		while (arr[right] > arr[mid])
		{
			right--;
		}
		if (left <= right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	
	if (right > 0)
		dar_QSortOfArray(arr, right);
	if (left < size)
		dar_QSortOfArray(arr + left,  size - left);
}

int main()
{
	int arr[] = {6,69,32,78,5};
	int b = std::size(arr);
	std::cout << dar_Sum(arr, 5) << std::endl;
	std::cout << b << std::endl;
	int MAX = 0;
	MAX = dar_FindMaxOfArray(arr, 5);
	std::cout << MAX << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	dar_QSortOfArray(arr, 5);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}