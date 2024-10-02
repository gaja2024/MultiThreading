#pragma once
#include "DataManager.h"
#include "DataSorter.h"
#include "ParallelDataSorter.h"
#include "PerformanceAnalyzer.h"
DataManager::DataManager()
{
	m_DataGenerator = new DataGenerator();
	std::vector<std::vector<int>>dataList = m_DataGenerator->GetDataList();
	std::vector<std::vector<int>>dataListParallel = dataList;
	DataSorter dataSort(dataList);
	auto performanceData = dataSort.GetPerformanceData();
	ParallelDataSorter dataSortParallel(dataListParallel);
	auto performanceDataParallel = dataSortParallel.GetPerformanceData();
	PerformanceAnalyser perf(performanceData, performanceDataParallel);
}

DataManager::~DataManager()
{
	delete m_DataGenerator;
}
