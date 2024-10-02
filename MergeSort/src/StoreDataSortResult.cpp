#include "StoreDataSortResult.h"
void WriteDataSortResultToFile(const std::vector<int> &result, int size, std::string strThreadType)
{
	std::string strDataFile = "Data_Sort_Result_" + strThreadType + "_" + std::to_string(size) +  ".txt";
	std::ofstream dataFile(strDataFile, std::ios_base::out);
	for (const auto &element : result)
	{
		dataFile << element << " ";
	}
}