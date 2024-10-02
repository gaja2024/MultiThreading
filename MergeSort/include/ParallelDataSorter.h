#pragma once
#include <vector>
#include "PerformanceData.h"
class ParallelDataSorter
{
public:
	ParallelDataSorter() = default;
	ParallelDataSorter(std::vector<std::vector<int>>&dataList);
	std::vector<PerformanceData> GetPerformanceData() { return m_perFormanceDataList; }
private:
	std::vector< PerformanceData>m_perFormanceDataList;
	void DoMergeSort(std::vector<int>&data, int start, int end);
	void Merge(std::vector<int>& data, int start, int mid, int end);
	void DoParallelSort(std::vector<int>&data, int start, int end);
	void MergeSortedChunks(std::vector<int>&data);
	void MergeParallelChunks(std::vector<int>&data, int start, int nChunkSize, int end);
	int m_nNumThreads = 0;
};

