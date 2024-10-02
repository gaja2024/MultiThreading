#pragma once
#include <chrono>
class PerformanceData
{
public:
	PerformanceData(unsigned int nMatrixFirstRow, unsigned int m_nMatrixFirstCol, unsigned int nMatrixSecondCol, std::chrono::duration<double> dDuration);
	~PerformanceData();
	PerformanceData();
	int GetFirstMatrixRow() const {return m_nMatrixFirstRow;}
	int GetFirstMatrixColumn() const { return m_nMatrixFirstCol; }
	int GetSecondMatrixColumn() const { return m_nMatrixSecondCol; }
	std::chrono::duration<double> GetTimeDuration() const { return m_dDuration; }
private:
	int m_nMatrixFirstRow;
	int m_nMatrixFirstCol;
	int m_nMatrixSecondCol;
	std::chrono::duration<double> m_dDuration;
};

