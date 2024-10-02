#pragma once
#include <vector>
#include "PerformanceData.h"
class MatrixMultiplier
{
public:
	MatrixMultiplier(const std::vector<std::vector<std::vector<int>>>&firstMatrixList,
		const std::vector<std::vector<std::vector<int>>>&secondMatrixList);
	std::vector<PerformanceData> GetPerformanceData() { return m_perFormanceDataList; }
private:
	std::vector< PerformanceData>m_perFormanceDataList;
	void Multiply2Matrix(const std::vector<std::vector<int>>&firstMatrix, const std::vector<std::vector<int>>&secondMatrix,
		std::vector<std::vector<int>>& result);
};

