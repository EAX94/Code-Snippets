#include <algorithm>
#include <cctype>

size_t FindStringInString(std::string buffer, std::string find, bool caseInsensitive = true) {
	if(caseInsensitive) {
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), std::tolower);
		std::transform(find.begin(), find.end(), find.begin(), std::tolower);
	}

	return buffer.find(find);
}
