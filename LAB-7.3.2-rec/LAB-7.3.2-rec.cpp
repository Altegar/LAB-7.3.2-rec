// LAB-7.3.2-iter.cpp
// Сушинський Ігор
// Лабораторна робота №7.3
// Опрацювання динамічних багатовимірних масивів.
// Варіант 18
// Рекурсивний спосіб.

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Random(int** a, const int k, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int k, const int n, int i, int j);
void Part2_Number(int** a, const int k, const int n, int b, int max, int& c);

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	srand((unsigned)time(NULL));

	int Low = -12;
	int High = 23;

	int k, n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Random(a, k, n, Low, High, 0, 0);
	Print(a, k, n, 0, 0);
	int b = 0;
	int max = 0;
	int c = 0;

	Part2_Number(a, k, n, b, max, c);
	cout << "C = " << c << endl;


	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Random(int** a, const int k, const int n, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);

	if (j < n - 1)
		Random(a, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Random(a, k, n, Low, High, i + 1, 0);
}

void Print(int** a, const int k, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Print(a, k, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void Part2_Number(int** a, const int k, const int n, int b, int max, int& c)
{
	c = 0;
	b = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[i][j] == a[i][j + 1])
			{
				b++;

				if (b >= max)
				{
					max = b;
					c = i++;
					break;
				}
			}
		}
	}
}