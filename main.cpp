#include "stdafx.h"
#include "Engine.h"
#include "World.h"

int Ascending(const void* A, const void* B)
{
	if (*(int*)A - *(int*)B > 0)
		return 1;
	if (*(int*)A - *(int*)B < 0)
		return -1;
	return 0;
}

int Desending(const void* A, const void* B)
{
	if (*(int*)A - *(int*)B > 0)
		return -1;
	if (*(int*)A - *(int*)B < 0)
		return 1;
	return 0;
}

void Swap(void* A, void* B, size_t Size)
{
	std::vector<char> Temp(Size);
	std::memcpy(Temp.data(), A, Size);
	std::memcpy(A, B, Size);
	std::memcpy(B, Temp.data(), Size);
}

void Sort(void* InData, size_t Count, size_t Size, int (*Compare)(const void*, const void*))
{
	char* Ptr = (char*)InData;
	for (int i = 0; i < Count - 1; ++i)
	{
		for (int j = i + 1; j < Count; ++j)
		{
			if (Compare((Ptr + Size * i), (Ptr + Size * j)) > 0)
			{
				Swap((Ptr + Size * i), (Ptr + Size * j), Size);
			}
		}
	}
}

void SelectionSort(int* InData, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			if (InData[i] < InData[j])
			{
				int Temp = InData[i];
				InData[i] = InData[j];
				InData[j] = Temp;
			}
		}
	}
}

int main()
{
	/*GEngine->GetWorld()->Load("NewLevel.txt");

	GEngine->Run();

	delete GEngine;*/

	int Data[10] = { 9, 1, 3, 5, 4, 6, 7, 8, 2, 10 };
	
	// SelectionSort(Data, 10);
	// Sort(Data, 10, sizeof(int), Ascending);
	Sort(Data, 10, sizeof(int), Desending);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << Data[i] << " ";
	}

	return 0;
}