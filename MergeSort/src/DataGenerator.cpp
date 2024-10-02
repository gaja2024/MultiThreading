#include "DataGenerator.h"
#include <fstream>


DataGenerator::DataGenerator()
{
	std::ifstream dataFile("DataSize.txt", std::ios_base::in);
	unsigned int nNumberOfDataList = 0;
	dataFile >> nNumberOfDataList;
	m_DataList.resize(nNumberOfDataList);
	unsigned int nSizeOfData = 0;
	for (unsigned int i = 0; i < nNumberOfDataList; ++i)
	{
		dataFile >> nSizeOfData;
		std::string strDataList = "Data_" + std::to_string(nSizeOfData) +".txt";
		GenerateData(m_DataList[i], nSizeOfData, strDataList);
		
	}
}
void DataGenerator::GenerateData(std::vector<int>& data, const unsigned int nSize, std::string strDataFile)
{
	std::ofstream dataFitale(strDataFile, std::ios_base::out);
	data.resize(nSize);
	for (unsigned int i = 0; i < nSize; ++i)
	{
		data[i] = (rand() % nSize) + 1;
		dataFitale << data[i] << " ";
	}
	dataFitale << std::endl;
}
std::vector<std::vector<int>> DataGenerator::GetDataList()
{
	return m_DataList;
}

