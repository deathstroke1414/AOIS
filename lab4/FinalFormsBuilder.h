#pragma once
#include<vector>
#include<map>
#include<string>
#include<set>
class FinalFormsBuilder {
public:
	inline std::vector<std::string> splitExpression(std::string& expression);
	inline std::vector<std::string> findUniqueVariables(std::vector<std::string>& expressions);
	inline int countUniqueVariables(std::vector<std::string>& expressions);
	inline std::vector<std::string> convertLogicToNumeric
	(std::vector<std::string>& logicStrings, std::vector<std::string>& uniqueVars);
	std::vector<std::string> findMerges(std::vector<std::string>& strings, int N);
	inline bool canMerge(std::string& a, std::string& b, int N);
	std::string mergeStrings(std::string& a, std::string& b, int N);
	std::vector<std::string> numericStringsToVariables
	(std::vector<std::string>& numericStrings, std::vector<std::string>& uniqueVariables);
	inline bool isContained(std::string& candidate, std::string& target);
	std::vector<std::vector<bool>> buildCoverageMatrix
	(std::vector<std::string>& before, std::vector<std::string>& after);
	std::vector<std::string> findExtraStrings(std::vector<std::string>& after, std::vector<std::vector<bool>>& coverageMatrix);
	std::vector<std::string>removeStrings(std::vector<std::string>& input, std::vector<std::string>& toRemove);
	std::string vectorToStringDNF(std::vector<std::string>& vec);
	inline void TDNFCalcTable(std::string& input);
};