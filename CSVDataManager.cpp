#include "CSVDataManager.h"

CSVDataManager::CSVDataManager(const std::string& filename) : filename(filename) {}

void CSVDataManager::createRow(const std::vector<std::string>& rowData) {
	std::ofstream file(filename, std::ios::app);

	try
	{
		file.is_open();
			for (size_t i = 0; i < rowData.size(); i++) {
				file << rowData[i];
				if (i < rowData.size() - 1) {
					file << ",";
				}
			}
			file << "\n";
			file.close();
			std::cout << "Row insterted successfully.\n";
		

	}
	catch (const std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
		std::cerr << "Unable to open the file for writing.\n ";
	}

}



void CSVDataManager::readRow() {
	std::ifstream file(filename);
	
	try
	{
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::vector<std::string>row = splitCSVLine(line);
				for (const std::string& cell : row) {
					std::cout << cell << "\t";
				}
				std::cout << "\n";
			}
			file.close();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
		std::cerr << "Unable to open the file for reading. \n";
	}
}

void CSVDataManager::readNbrOfRow(int nbr) {
	std::ifstream file(filename);
	int i = 0;
	try
	{
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)&&i<nbr) {
				std::cout << line;
				std::vector<std::string>row = splitCSVLine(line);
				for (const std::string& cell : row) {
					std::cout << cell << "\t";
				}
				std::cout << "\n";
				i++;
			}
			file.close();
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
		std::cerr << "Unable to open the file for reading. \n";
	}
}

void CSVDataManager::updateRow(int rowIndex, const std::vector<std::string>& newData) {
	std::ifstream file(filename);
	std::ofstream tempFile("C:/Users/chris/Development/CSV/temp.csv");

	try
	{
		file.is_open() && tempFile.is_open();
			std::string line;
			int currentIndex = 0;

			while (std::getline(file, line)) {
				if (currentIndex == rowIndex) {
					for (size_t i = 0; i < newData.size(); i++) {
						tempFile << newData[i];
						if (i < newData.size() - 1) {
							tempFile << ",";
						}
					}
					tempFile << "\n";
				}
				else {
					tempFile << line << "\n";
				}
				currentIndex++;
			}
			file.close();
			tempFile.close();

			if (std::rename("C:/Users/chris/Development/CSV/temp.csv", filename.c_str()) != 0) {
				std::cerr << "Error updating row.\n";
			}
			else {
				std::cout << "Row updated successfully.\n";
			}
		
	}
	catch (const std::exception&e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
		std::cerr << "Unable to open the file(s) for updating. \n";
	}
}


void CSVDataManager::deleteRow(int rowIndex) {
	std::ifstream file(filename);
	std::ofstream tempFile("temp.csv");

	try
	{

		if (file.is_open() && tempFile.is_open()) {
			std::string line;
			int currentIndex = 0;

			while (std::getline(file, line)) {
				if (currentIndex != rowIndex) {
					tempFile << line << "\n";
				}
				currentIndex++;
			}
			file.close();
			tempFile.close();

			if (std::rename("temp.csv", filename.c_str()) != 0) {
				std::cerr << "Error deleting row.\n";
			}
			else {
				std::cout << "Row deleted successfully.\n";
			}
		}
	}
	catch (const std::exception&e)
	{
		std::cerr << "exception caught: " << e.what() << '\n';
		std::cerr << "Unable to open the file(s) for deleting.\n";
	}
}


void CSVDataManager::searchRow(const std::string& searchWord) {
	std::ifstream file(filename);

	try {
		if (file.is_open()) {
			std::string line;
			int rowIndex = 0;

			while (std::getline(file, line)) {
				std::vector<std::string> row = splitCSVLine(line);
				bool rowContainsWord = false;

				for (const std::string& cell : row) {
					if (cell == searchWord) {
						rowContainsWord = true;
						break; 
					}
				}

				if (rowContainsWord) {
					std::cout << "Row " << rowIndex << ": ";
					for (const std::string& cell : row) {
						std::cout << cell << "\t";
					}
					std::cout << "\n";
				}

				rowIndex++;
			}

			file.close();
		}
		else {
			std::cerr << "Unable to open the file for reading.\n";
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
}


std::vector<std::string> CSVDataManager::splitCSVLine(const std::string& line) {
	std::vector<std::string>result;
	std::stringstream ss(line);
	std::string cell;
	while (std::getline(ss, cell, ',')) {
		result.push_back(cell);
	}
	return result;
}