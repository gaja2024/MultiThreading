
#include "MatrixManager.h"
#include  "MatrixGenerator.h"
#include "MatrixMultiplier.h"
#include "ParallelMatrixMultiplier.h"
#include "PerformanceAnalyser.h"
MatrixManager::MatrixManager()
{
	m_MatrixGenerator = new MatrixGenerator();
	std::vector<std::vector<std::vector<int>>>matrix_List_First, matrix_List_Second;
	m_MatrixGenerator->GetMatrixList(matrix_List_First, matrix_List_Second);
	MatrixMultiplier matMul(matrix_List_First, matrix_List_Second);
	auto performanceData = matMul.GetPerformanceData();
	ParallelMatrixMultiplier matMulParallel(matrix_List_First, matrix_List_Second);
	auto performanceDataParallel = matMulParallel.GetPerformanceData();
	PerformanceAnalyser perf(performanceData, performanceDataParallel);
}

MatrixManager::~MatrixManager()
{
	delete m_MatrixGenerator;
}
