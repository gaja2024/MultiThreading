#include <chrono>
#include "MatrixMultiplier.h"
#include "StoreMatrixMultiplicationResult.h"



MatrixMultiplier::MatrixMultiplier(const std::vector<std::vector<std::vector<int>>>&firstMatrixList,
	const std::vector<std::vector<std::vector<int>>>&secondMatrixList)
{
	unsigned int nMatrixListSize = firstMatrixList.size();
	m_perFormanceDataList.resize(nMatrixListSize);
	for (unsigned int i = 0; i < nMatrixListSize; ++i)
	{
		std::vector<std::vector<int>> result(firstMatrixList[i].size(), std::vector<int>(secondMatrixList[i][0].size()));
		auto start = std::chrono::high_resolution_clock::now();
		Multiply2Matrix(firstMatrixList[i], secondMatrixList[i], result);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		m_perFormanceDataList[i] = { firstMatrixList[i].size(),firstMatrixList[i][0].size(),secondMatrixList[i][0].size(),duration };
		WriteMatrixMultiplicationResultToFile(result, firstMatrixList[i].size(), secondMatrixList[i][0].size(), "ST");
	}
}

void MatrixMultiplier::Multiply2Matrix(const std::vector<std::vector<int>>&firstMatrix, const std::vector<std::vector<int>>&secondMatrix,
	std::vector<std::vector<int>> &result)
{
	for (unsigned int row = 0; row < result.size(); ++row) {
		for (unsigned int col = 0; col < result[0].size(); ++col) {
			for (unsigned int inner = 0; inner < secondMatrix.size(); ++inner) {
				result[row][col] += firstMatrix[row][inner] * secondMatrix[inner][col];
			}
		}
	}
}

