#include "StoreMatrixMultiplicationResult.h"
void WriteMatrixMultiplicationResultToFile(std::vector<std::vector<int>> result, int row, int col, std::string strThreadType)
{
	std::string strMatrixFile = "Matrix_Result_" + strThreadType + "_" + std::to_string(row) + "x" + 
		std::to_string(col) + ".txt";
	std::ofstream matrixFile(strMatrixFile, std::ios_base::out);
	for (const auto &row : result)
	{
		for (const auto &col : row)
		{
			matrixFile << col << " ";
		}
		matrixFile << std::endl;
	}
}