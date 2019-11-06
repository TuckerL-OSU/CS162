/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Project 1: Langton's Ant Simulation
* Array.hpp
******************************************************************************/
// https://www.codeproject6com/Articles/21909/Introduction-to-dynamic-two-dimensional-arrays-in
template <typename T>
T **AllocateDynamicArray(int nRows, int nCols)
{
	T **dynamicArray;

	dynamicArray = new T*[nRows];
	for (int i = 0; i < nRows; i++)
		dynamicArray[i] = new T[nCols];

	return dynamicArray;
}

template <typename T>
void FreeDynamicArray(T** dArray, int rows)
{
	for (int i = 0; i < rows; ++i) {
		delete[] dArray[i];
	}
	delete[] dArray;
}