#include <iostream>
#include <vector>


int posMin(std::vector<int>& v, int left, int right)
{
	int minIndex = left;
	for (int i = left + 1; i < right; i++)
	{
		if (v[i] < v[minIndex])
			minIndex = v[i];
	}
	return minIndex;
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void selectionSort(std::vector<int>& v)
{
	int last = v.size();
	for (int i = 0; i < last; i++)
	{
		int minIndex = posMin(v, i, last);
		swap(v[minIndex], v[i]);
	}
}

void InsertionSort(std::vector<int>& v)
{
	for (int i = 1; )
	{
		int x = v[i];
		int j = i;
	}
}

int main()
{
	std::vector<int> v = { 3, -1, 10, 200 };
	selectionSort(v);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	return 0;
}