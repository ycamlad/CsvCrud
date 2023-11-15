#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include<iterator>

struct header {
	std::string year;
	std::string aggregation;
};

class CSVDataManager{
public:

	CSVDataManager(const std::string& filename);

	void createRow(const std::vector<std::string>& rowData);

	void readRow();
	void readNbrOfRow(int nbr);

	void updateRow(int rowIndex,const std::vector<std::string>& newData);

	void deleteRow(int rowIndex);

	void searchRow(const std::string& searchWord);

private:

	std::string filename;

	std::vector<std::string> splitCSVLine(const std::string& line);
};
