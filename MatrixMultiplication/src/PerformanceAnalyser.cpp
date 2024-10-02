#include "PerformanceAnalyser.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
template<typename T>
std::string prd(T x, const int decDigits, const int width) {
	std::stringstream ss;
	ss.fill(' ');        // fill space around displayed #
	ss.width(width);     // set  width around displayed #
	ss.precision(decDigits); // set # places after decimal
	ss << x;
	return ss.str();
}

std::string center(const std::string s, const int w) {
	std::stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();    // format with padding
	if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
		ss << " ";
	return ss.str();
}
PerformanceAnalyser::PerformanceAnalyser(const std::vector<PerformanceData>&performanceDataSingleThreaded,
	const std::vector<PerformanceData>&performanceDataMultiThreaded)
{

	std::ofstream matrixFile("performanceAnalysis.txt", std::ios_base::out);
	matrixFile << center("1st Matrix Rows", 10) << " | "
		<< center("1st Matrix Cols", 10) << " | "
		<< center("2nd Matrix Rows", 10) << " | "
		<< center("2nd Matrix Cols", 10) << " | "
		<< center("Time Normal", 10) << " | "
		<< center("Time Parallel", 10) << " | "
		<< center("Efficiency = (Normal/Parallel)*100%", 10) << "\n";

	matrixFile << std::string(150, '-') << "\n";
	int nSize = performanceDataSingleThreaded.size();
	for (int i = 0; i < nSize; ++i)
	{
		matrixFile << prd(performanceDataSingleThreaded[i].GetFirstMatrixRow(), 0, 15) << " | " 
			<< prd(performanceDataSingleThreaded[i].GetFirstMatrixColumn(), 0, 15) << " | "
			<< prd(performanceDataSingleThreaded[i].GetFirstMatrixColumn(), 0, 15) << " | "
			<< prd(performanceDataSingleThreaded[i].GetSecondMatrixColumn(), 0, 15) << " | "
			<< prd(performanceDataSingleThreaded[i].GetTimeDuration().count(), 4, 11) << " | "
			<< prd(performanceDataMultiThreaded[i].GetTimeDuration().count(), 4, 13) << " | "
			<< prd(performanceDataSingleThreaded[i].GetTimeDuration().count()*100/ performanceDataMultiThreaded[i].GetTimeDuration().count(), 2, 10) << "\n";
	}
	
}

