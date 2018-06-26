#include <iostream>
using namespace std;

void Swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}

void My_sort(int *data, const int len)
{
	for (int i = 0; i < len; i++)
		for (int j = i; j < len; j++)
			if (data[i] > data[j])
				Swap(data[i], data[j]);
}

void Selection_sort(int *data, int len)
{ // �ð����⵵ : n^2
	int min_index;
	int temp;
	for (int i = 0; i < len - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < len; j++) {
			if (data[min_index] > data[j])
				min_index = j;
		}
		temp = data[min_index];
		data[min_index] = data[i];
		data[i] = temp;
	}
}

void Insertion_sort(int *data, int len)
{ // �ð����⵵ : n (best) ~ n^2 (worst) / 354p ��ĭä��� ����
	int temp, j, i;
	for (i = 1; i < len; i++) {
		temp = data[i];
		for (j = i - 1; j >= 0 && temp < data[j]; j--)
			data[j + 1] = data[j];
		data[j + 1] = temp;
	}
}

int partition(int *data, int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = data[left];
	do {
		do
			low++;
		while (low <= right && data[low] < pivot);
		do
			high--;
		while (high >= left && data[high] > pivot);
		if (low < high) {
			temp = data[low];
			data[low] = data[high];
			data[high] = temp;
		}
	} while (low < high);
	temp = data[left];
	data[left] = data[high];
	data[high] = temp;
	return high;
}

void Quick_sort(int *data, int left, int right)
{ // �ð����⵵ : nlogn (best) ~ n^2 (worst) / �������� ���ĵǾ� �ִ� ��찡 worst ��Ȳ
	if (left < right) {
		int q = partition(data, left, right);
		Quick_sort(data, left, q - 1);
		Quick_sort(data, q + 1, right);
	}
}

void main()
{
	int data[10] = { 3,5,1,8,10,4,6,2,7,9 };
	//	Selection_sort(data, 10); // ���� ����
	//	Insertion_sort(data, 10); // ���� ����
	Quick_sort(data, 0, 9); // �� ����

							//	My_sort(data, 10);

	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";

}