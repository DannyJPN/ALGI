#include <iostream>

using namespace std;

const int NumberOfRows = 10;
const int NumberOfColumns = 10;
const int NumberOfGenerations = 10;
const int NumberOfLivingCells = 50;

bool IsCellAlive(const bool Colony[NumberOfRows][NumberOfColumns], const int Row, const int Column)
{
	if (0 <= Row && Row < NumberOfRows && 0 <= Column && Column < NumberOfColumns)
	{
		return Colony[Row][Column];
	}
	return false;
}

void main()
{
	bool a[NumberOfRows][NumberOfColumns], b[NumberOfRows][NumberOfColumns];
	int i, j, k, l, p, q;
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
				for (p = j - 1; p <= j + 1; p++)
					for (q = k - 1; q <= k + 1; q++)
						if ((p != j || q != k) && IsCellAlive(a, p, q))
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
