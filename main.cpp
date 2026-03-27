#include "stdafx.h"
#include "Engine.h"
#include "World.h"

int Ascending(const void* A, const void* B)
{
	return (*(int*)A - *(int*)B > 0) ? 1 : -1;
}

int Desending(const void* A, const void* B)
{
	return (*(int*)A - *(int*)B < 0) ? 1 : -1;
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
	for (int i = 0; i < Size - 1; ++i)
	{
		for (int j = i + 1; j < Size; ++j)
		{
			if (InData[i] > InData[j])
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
	GEngine->GetWorld()->Load("NewLevel.txt");

	GEngine->Run();

	delete GEngine;

	//int Data[15] = { 9, 1, 3, 5, 4, 6, 7, 8, 2, 10 , 15, 14, 13, 12, 11};
	//
	//// Sort(Data, 15, sizeof(int), Ascending);
	//// Sort(Data, 15, sizeof(int), Desending);

	//int Number = 0;

	//Sort(Data, 15, sizeof(int), [](const void* A, const void* B) -> int
	//	{
	//		return (*(int*)A - *(int*)B > 0) ? 1 : -1;
	//	});

	//Sort(Data, 15, sizeof(int), [](const void* A, const void* B) -> int
	//	{
	//		return (*(int*)A - *(int*)B < 0) ? 1 : -1;
	//	});

	//for (int i = 0; i < 15; ++i)
	//{
	//	std::cout << Data[i] << " ";
	//}

	return 0;
}