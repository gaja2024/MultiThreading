#pragma once
#include <vector>
#include <cstdlib>
#include <string>

class MatrixGenerator
{
public:
	MatrixGenerator();
	void GetMatrixList(std::vector<std::vector<std::vector<int>>>&matrix_List_First, std::vector<std::vector<std::vector<int>>>&matrix_List_Second);
private:
	std::vector<std::vector<std::vector<int>>>m_Matrix_List_First;
	std::vector<std::vector<std::vector<int>>>m_Matrix_List_Second;
	void GenerateMatrix(std::vector<std::vector<int>>& matrix, const unsigned int nRow, const unsigned int nColumn,std::string strMatrixFile);
	
};

