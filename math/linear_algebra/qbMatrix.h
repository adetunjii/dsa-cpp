#ifndef QBMATRIX_H
#define QBMATRIX_H

template<class T>
class qbMatrix{
	public:
	qbMatrix();
	qbMatrix(int nRows, int nCols);
	qbMatrix(int nRows, int nCols, const T *inputData);
	qbMatrix(const qbMatrix<T>& inputData);

	~qbMatrix();

	bool resize(int numRows, int numCols);

	T GetElement(int row, int col);
	bool SetElement(int row, int col, T elem);
	int GetNumRows();
	int GetNumCols();

	// Operator override
	bool operator== (const qbMatrix<T>& rhs);

	template <class U> friend qbMatrix<U> operator+ (const qbMatrix<U>& lhs, const qbMatrix<U>& rhs);
}
