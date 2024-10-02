#include "MatrixGenerator.h"
#include <fstream>



MatrixGenerator::MatrixGenerator()
{
	std::ifstream matrixFile("MatrixSize.txt", std::ios_base::in);
	unsigned int nNumberOfMatrix = 0;
	matrixFile >> nNumberOfMatrix;
	m_Matrix_List_First.resize(nNumberOfMatrix);
	m_Matrix_List_Second.resize(nNumberOfMatrix);
	unsigned int nFirstMatrixRowSize = 0;
	unsigned int nFirstMatrixColSize = 0;
	unsigned int nSecondMatrixRowSize = 0;
	unsigned int nSecondMatrixColSize = 0;
	for (unsigned int i = 0; i < nNumberOfMatrix; ++i)
	{
		matrixFile >> nFirstMatrixRowSize >> nFirstMatrixColSize >> nSecondMatrixColSize;
		nSecondMatrixRowSize = nFirstMatrixColSize;
		std::string strMatrix = "Matrix_First_" + std::to_string(nFirstMatrixRowSize) + "x" + std::to_string(nFirstMatrixColSize) + ".txt";
		GenerateMatrix(m_Matrix_List_First[i], nFirstMatrixRowSize, nFirstMatrixColSize, strMatrix);
		strMatrix = "Matrix_Second_" + std::to_string(nFirstMatrixRowSize) + "x" + std::to_string(nFirstMatrixColSize) + ".txt";
		GenerateMatrix(m_Matrix_List_Second[i], nSecondMatrixRowSize, nSecondMatrixColSize, strMatrix);
	}
}
void MatrixGenerator::GenerateMatrix(std::vector<std::vector<int>>& matrix, const unsigned int nRow, const unsigned int nColumn, std::string strMatrixFile)
{
	std::ofstream matrixFile(strMatrixFile, std::ios_base::out);
	matrix.resize(nRow);
	for (unsigned int j = 0; j < nRow; ++j)
	{
		matrix[j].resize(nColumn);
		
		for (unsigned int k = 0; k < nColumn; ++k)
		{
			//matrix[j][k] = (rand() % 9) + 1;
			matrix[j][k] = ((j*nRow+k) % 9) + 1;
			matrixFile << matrix[j][k] << " ";
		}
		matrixFile << std::endl;
	}
}
void MatrixGenerator::GetMatrixList(std::vector<std::vector<std::vector<int>>>&matrix_List_First,
	std::vector<std::vector<std::vector<int>>>&matrix_List_Second)
{
	matrix_List_First = m_Matrix_List_First;
	matrix_List_Second = m_Matrix_List_Second;
}

