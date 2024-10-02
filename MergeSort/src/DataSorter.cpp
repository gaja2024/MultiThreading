#pragma once
#include <chrono>
#include <string>
#include <fstream>
#include "DataSorter.h"
#include "StoreDataSortResult.h"

DataSorter::DataSorter( std::vector<std::vector<int>>&dataList)
{
	unsigned int nDataListSize = dataList.size();
	m_perFormanceDataList.resize(nDataListSize);
	for (unsigned int i = 0; i < nDataListSize; ++i)
	{
		auto start = std::chrono::high_resolution_clock::now();
		DoMergeSort(dataList[i], 0, dataList[i].size()-1);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		m_perFormanceDataList[i] = { dataList[i].size(),duration };
		WriteDataSortResultToFile(dataList[i], dataList[i].size(), "ST");
	}
}
void DataSorter::Merge(std::vector<int>& data, int start, int mid, int end) {
	int i, j, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;

	// Create temporary vectors
	std::vector<int> leftVec(n1), rightVec(n2);

	// Copy data to temporary vectors
	for (i = 0; i < n1; i++)
		leftVec[i] = data[start + i];
	for (j = 0; j < n2; j++)
		rightVec[j] = data[mid + 1 + j];

	// Merge the temporary vectors back into vec[left..right]
	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (leftVec[i] <= rightVec[j]) {
			data[k] = leftVec[i];
			i++;
		}
		else {
			data[k] = rightVec[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of leftVec[], if any
	while (i < n1) {
		data[k] = leftVec[i];
		i++;
		k++;
	}

	// Copy the remaining elements of rightVec[], if any
	while (j < n2) {
		data[k] = rightVec[j];
		j++;
		k++;
	}
}
void DataSorter::DoMergeSort(std::vector<int>&data, int start, int end)
{
	if (start < end) {

		// Calculate Mid Point
		int mid = start + (end - start) / 2;

		// Sort first half
		DoMergeSort(data, start, mid);
		// Sort second half
		DoMergeSort(data, mid + 1, end);
		// Merge the sorted halves
		Merge(data, start, mid, end);
	}
}

