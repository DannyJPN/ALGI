#include <iostream>

using namespace std;

const int NumberOfRows = 10;
const int NumberOfColumns = 10;
const int NumberOfGenerations = 10;
const int NumberOfLivingCells = 50;

void main()
{
	bool a[NumberOfRows][NumberOfColumns], b[NumberOfRows][NumberOfColumns];
	int i, j, k, l;
	for (i = 0; i < NumberOfRows; i++)
		for (j = 0; j < NumberOfColumns; j++)
			a[i][j] = false;
	for (i = 0; i < NumberOfLivingCells; i++)
	{
		j = rand() % NumberOfRows;
		k = rand() % NumberOfColumns;
		a[j][k] = true;
	}
	cout << "Puvodni kolonie" << endl;
	for (i = 0; i < NumberOfRows; i++)
	{
		for (j = 0; j < NumberOfColumns; j++)
		{
			if (a[i][j])
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl;
	for (i = 1; i <= NumberOfGenerations; i++)
	{
		for (j = 0; j < NumberOfRows; j++)
			for (k = 0; k < NumberOfColumns; k++)
			{
				l = 0;
				if (0 <= (j - 1) && (j - 1) < NumberOfRows && 0 <= (k - 1) && (k - 1) < NumberOfColumns && a[j - 1][k - 1])
					l += 1;
				if (0 <= (j - 1) && (j - 1) < NumberOfRows && 0 <= k && k < NumberOfColumns && a[j - 1][k])
					l += 1;
				if (0 <= (j - 1) && (j - 1) < NumberOfRows && 0 <= (k + 1) && (k + 1) < NumberOfColumns && a[j - 1][k + 1])
					l += 1;
				if (0 <= j && j < NumberOfRows && 0 <= (k - 1) && (k - 1) < NumberOfColumns && a[j][(k - 1)])
					l += 1;
				if (0 <= j && j < NumberOfRows && 0 <= (k + 1) && (k + 1) < NumberOfColumns && a[j][k + 1])
					l += 1;
				if (0 <= (j + 1) && (j + 1) < NumberOfRows && 0 <= (k - 1) && (k - 1) < NumberOfColumns && a[j + 1][k - 1])
					l += 1;
				if (0 <= (j + 1) && (j + 1) < NumberOfRows && 0 <= k && k < NumberOfColumns && a[j + 1][k])
					l += 1;
				if (0 <= (j + 1) && (j + 1) < NumberOfRows && 0 <= (k + 1) && (k + 1) < NumberOfColumns && a[j + 1][k + 1])
					l += 1;
				if (a[j][k] && l == 2 || l == 3)
					b[j][k] = true;
				else
					b[j][k] = false;
			}
		for (j = 0; j < NumberOfRows; j++)
			for (k = 0; k < NumberOfColumns; k++)
				a[j][k] = b[j][k];
		cout << "Generace #" << i << endl;
		for (j = 0; j < NumberOfRows; j++)
		{
			for (k = 0; k < NumberOfColumns; k++)
			{
				if (a[j][k])
					cout << "X";
				else
					cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}
}
