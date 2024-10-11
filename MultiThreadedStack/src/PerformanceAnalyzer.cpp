#include "PerformanceAnalyzer.h"
#include <iomanip>
#include <fstream>
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
void DoPerformanceAnalysis(int nNumThreads, int nNumIterations, double duration_StackWithLock, double duration_StackLockFree, std::string strFile)
{
	std::ofstream performanceFile(strFile, std::ios_base::app);
	static int firstTime = 0;
	if (0 == firstTime)
	{
		performanceFile << center("Thread count", 10) << " | "
			<< center("Iteration count per thread", 10) << " | "
			<< center("Time Taken for Stack with Lock", 10) << " | "
			<< center("Time Taken for Stack Lock free", 10) << " | "
			<< center("Efficiency = (Lock/Lock free)*100%", 10) << "\n";
		performanceFile << std::string(150, '-') << "\n";
	}
	
	performanceFile << prd(nNumThreads, 0, 12) << " | "
		<< prd(nNumIterations, 0, 26) << " | "
		<< prd(duration_StackWithLock, 4, 30) << " | "
		<< prd(duration_StackLockFree, 4, 30) << " | "
		<< prd(duration_StackWithLock * 100 / duration_StackLockFree, 2, 10) << "\n";
	++firstTime;

}


