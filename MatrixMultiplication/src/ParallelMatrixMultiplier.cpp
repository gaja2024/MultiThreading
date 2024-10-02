#include "ParallelMatrixMultiplier.h"
#include <thread>
#include <chrono>
#include "StoreMatrixMultiplicationResult.h"

ParallelMatrixMultiplier::ParallelMatrixMultiplier(const std::vector<std::vector<std::vector<int>>>&firstMatrixList,
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
		WriteMatrixMultiplicationResultToFile(result, firstMatrixList[i].size(), secondMatrixList[i][0].size(), "MT");
	}
}
void ParallelMatrixMultiplier::ParallelMultiply2Matrix(const std::vector<std::vector<int>>&firstMatrix, 
	const std::vector<std::vector<int>>&secondMatrix,
	std::vector<std::vector<int>>&resultMatrix, unsigned int nRowStart, unsigned int nRowEnd )
{
	for (unsigned int row = nRowStart; row < nRowEnd; ++row) {
		for (unsigned int col = 0; col < resultMatrix[0].size(); ++col) {
			for (unsigned int inner = 0; inner < secondMatrix.size(); ++inner) {
				resultMatrix[row][col] += firstMatrix[row][inner] * secondMatrix[inner][col];
			}
		}
	}
}
void ParallelMatrixMultiplier::Multiply2Matrix(const std::vector<std::vector<int>>&firstMatrix, const std::vector<std::vector<int>>&secondMatrix,
	std::vector<std::vector<int>>& result)
{
	unsigned int nNumThreads = std::thread::hardware_concurrency();
	unsigned int nChunkSize = firstMatrix.size()/ nNumThreads;
	std::vector<std::thread> mulThread(nNumThreads);
	for (unsigned int i=0; i< nNumThreads;++i)
	{
		unsigned int start = i * nChunkSize;
		unsigned int end = (i == nNumThreads - 1) ? firstMatrix.size() : (i + 1) * nChunkSize;
		mulThread[i] = std::thread(&ParallelMatrixMultiplier::ParallelMultiply2Matrix, ParallelMatrixMultiplier(), std::ref(firstMatrix), std::ref(secondMatrix),
			std::ref(result), start, end);

	}
	// Wait for all the threads to finish
	for (auto& thread : mulThread) {
		thread.join();
	}
}

