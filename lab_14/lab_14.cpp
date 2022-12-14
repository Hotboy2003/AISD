#include <iostream>
const int N = 40;
const int n = 15;
int i = 0;

int Hashf(int a) 
{
	int b = a % N + i;
	return b;
}

void HashTable(int mas[N][N], int a)
{
	while (1) 
	{
		int b = Hashf(a);

		if (mas[b][0] == -1) 
		{
			mas[b][0] = a;
			i = 0;
			break;
		}
		else
		{
			i++;
		}
	}
}

void out(int mas[N][N]) 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			if (mas[i][j] != -1) 
			{
				std::cout << mas[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}

void posikChisl(int mas[N][N], int k) 
{
	for (int i = 0; i < N; i++) 
	{
		if (mas[k][i] != -1)
		{
			std::cout << mas[k][i] << " ";

		}
		else 
		{
			break;
		}
	}

}

int main()
{
	int hashtable[N][N];
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++)
		{
			hashtable[i][j] = -1;
		}
	}
	int mas[n];
	for (int i = 0; i < n; i++) 
	{
		mas[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) 
	{
		HashTable(hashtable, mas[i]);
	}
	out(hashtable);
}