#pragma once
#include <vector>
#include "PerformanceData.h"
class DataSorter
{
public:
	DataSorter(std::vector<std::vector<int>>&dataList);
	std::vector<PerformanceData> GetPerformanceData() { return m_perFormanceDataList; }
private:
	std::vector< PerformanceData>m_perFormanceDataList;
	void DoMergeSort(std::vector<int>&data, int start, int end);
	void Merge(std::vector<int>& data, int start, int mid, int end);
};

