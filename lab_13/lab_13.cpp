#include <iostream>
const int N = 20;
const int n = 15;

int Hashf(int a)
{
	int b = a % N;
	return b;
}

void HashTable(int mas[N][N], int a)
{
	int b = Hashf(a);
	if (mas[b][0] == 0) 
	{
		mas[b][0] = a;
	}
	else 
	{
		for (int i = 1; i < N; i++) {
			if (mas[b][i] == 0) 
			{
				mas[b][i] = a;
				break;
			}
		}
	}
}

void out(int mas[N][N]) 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			if (mas[i][j] != 0)
			{
				std::cout << mas[i][j] << " ";
			}
		}
		
	}
	std::cout << std::endl;
}

int poiskN(int y)
{

	int a = Hashf(y);
	return a;
}

void posikChisl(int mas[N][N], int k)
{

	for (int i = 0; i < N; i++)
	{
		if (mas[k][i] != 0) 
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
	int hashtable[N][N]; // создаем хеш таблицу
	//заполняем ее нулями
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			hashtable[i][j] = 0;
		}
	}
	int mas[n];
	// заполняем массив рандомными числами
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