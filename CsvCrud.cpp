#include "CSVDataManager.h"

int main()
{
	//std::string filePath = "C:\Users\chris\Development\CSV\annual-enterprise-survey-2021-financial-year-provisional-csv.csv";
	std::string filePath = "C://Users//chris//Development//CSV//annual-enterprise-survey-2021-financial-year-provisional-csv.csv"; 
	//std::string filePath2 = "C://Users//chris//Development//CSV//New Text Document.txt";
	std::vector<std::string> filePaths {};
	CSVDataManager csv(filePath);
	std::vector<std::string> newData{"2025","Level 1","99999","All industries","Dollars(millions)","H01","Total income","Financial performance","757504","ANZSIC06 divisions A - S(excluding classes K6330, L6711, O7552, O760, O771, O772, S9540, S9601, S9602,and S9603)"};
	std::vector<std::string> newData2{ "2025	Level 1	99999	All industries	Dollars (millions)	H01	Total income	Financial performance	757504	ANZSIC06 divisions A-S (excluding classes K6330, L6711, O7552, O760, O771, O772, S9540, S9601, S9602, and S9603)" };
	//csv.readRow();
	//csv.readNbrOfRow(2);
	csv.searchRow("AA");
	//csv.updateRow(2, newData);
	//csv.createRow(newData);
	return 0;
   
}



