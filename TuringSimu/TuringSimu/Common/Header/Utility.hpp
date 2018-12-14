#ifndef TM_UTILITY
#define TM_UTILITY
#include <vector>
//namespace ts_common {
	template <typename T>  bool vectorContains(std::vector<T> vector, T element) {
		return std::find(vector.begin(), vector.end(), element)!=vector.end();
	}

	/**
	 * \brief Splits the string by a given separator
	 * \param line The string to split
	 * \param separator The character to split by (this will NOT appear in any result string)
	 * \return A vector of strings which were split from the input string
	 */
inline std::vector<std::string> split(std::string line, char separator) {
		std::vector<std::string> returnSet;
		while (line.find(separator) != std::string::npos) {
			int const pos = line.find(separator);
			std::string substr = line.substr(0, pos);
			line.erase(0, pos + 1);
			returnSet.push_back(substr);
		}
		returnSet.push_back(line); //assuming that people do not end a line in the csv with the separator
		return returnSet;
	}

	//takes ';' as the separator
inline std::vector<std::string> split(std::string line) {
		return split(line, ';');
	}
//}
#endif