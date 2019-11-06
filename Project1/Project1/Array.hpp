// https://www.codeproject.com/Articles/21909/Introduction-to-dynamic-two-dimensional-arrays-in
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
void FreeDynamicArray(T** dArray)
{
	delete[] * dArray;
	delete[] dArray;
}