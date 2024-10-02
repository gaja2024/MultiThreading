#include <thread>
#include<algorithm>
#include <chrono>
#include <string>
#include <fstream>
#include "ParallelDataSorter.h"
#include "StoreDataSortResult.h"
ParallelDataSorter::ParallelDataSorter(std::vector<std::vector<int>>&dataList)
{
	unsigned int nDataListSize = dataList.size();
	m_perFormanceDataList.resize(nDataListSize);
	for (unsigned int i = 0; i < nDataListSize; ++i)
	{
		auto start = std::chrono::high_resolution_clock::now();
		DoMergeSort(dataList[i], 0, dataList[i].size() - 1);
		MergeSortedChunks(dataList[i]);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		m_perFormanceDataList[i] = { dataList[i].size(),duration };
		WriteDataSortResultToFile(dataList[i], dataList[i].size(), "MT");
	}
}

void ParallelDataSorter::Merge(std::vector<int>& data, int start, int mid, int end) {
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
void ParallelDataSorter::DoParallelSort(std::vector<int>&data, int start, int end)
{
	if (start < end) {

		// Calculate Mid Point
		int mid = start + (end - start) / 2;

		// Sort first half
		DoParallelSort(data, start, mid);
		// Sort second half
		DoParallelSort(data, mid + 1, end);

		// Merge the sorted halves
		Merge(data, start, mid, end);
	}
}
void ParallelDataSorter::MergeParallelChunks(std::vector<int>&data, int start, int nChunkSize,int end)
{
	std::inplace_merge(data.begin() + start, data.begin() + start + nChunkSize, data.begin() + end);
}
void ParallelDataSorter::MergeSortedChunks(std::vector<int>&data)
{
	int nChunkSize = data.size() / m_nNumThreads;
	while (nChunkSize < data.size())
	{
		int nPreviousChunkSize = nChunkSize;
		m_nNumThreads /= 2;
		nChunkSize *= 2;
		if (nChunkSize == data.size())
		{
			MergeParallelChunks(data, 0, nPreviousChunkSize, nChunkSize);
			break;
		}
		std::vector<std::thread>mergeThread(m_nNumThreads);
		
		for (int i = 0; i < m_nNumThreads; ++i)
		{
			int start = i * nChunkSize;
			int end = (i == m_nNumThreads - 1) ? data.size()  : (i + 1)*nChunkSize ;

			mergeThread[i] = std::thread(&ParallelDataSorter::MergeParallelChunks, ParallelDataSorter(), std::ref(data), start, nPreviousChunkSize,end);
		}
		for (auto &thread : mergeThread)
		{
			thread.join();
		}
	}
	
}
void ParallelDataSorter::DoMergeSort(std::vector<int>&data, int start, int end)
{
	m_nNumThreads = std::thread::hardware_concurrency();
	int nChunkSize = data.size() / m_nNumThreads;
	std::vector<std::thread>sortThreads(m_nNumThreads);
	for (unsigned int  i = 0; i < m_nNumThreads; ++i)
	{
		unsigned int start  = i * nChunkSize;
		unsigned int  end = (i == m_nNumThreads - 1) ? data.size()-1 :(i + 1)*nChunkSize-1;
		sortThreads[i] = std::thread(&ParallelDataSorter::DoParallelSort, ParallelDataSorter(), std::ref(data), start, end);
	}
	for (auto& thread : sortThreads)
	{
		thread.join();
	}
	
}

