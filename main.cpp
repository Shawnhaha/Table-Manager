#include "read.h"
#include "readTable.h"
#include "TableManager.h"
//#include "disabilityTable.h"
//#include "ageTable.h"
//#include "geographyTable.h"
using namespace std;

int main() {
	readDoc r;
	string filename;
	/*
	DisabilityTable distbl;
	AgeTable agetbl;
	GeographyTable geotbl;
	*/

	cout << "Please enter the main file's name:";
	cin >> filename;
	ifstream file(filename);
	vector <pair<string,string>> table_inputs = r.table_input(filename);
	string line;


	//For loop to construct the table objects
	//Passes the filename to the tables
	//First = filename
	//Second = table type
	for(vector<pair<string,string>>::iterator it=table_inputs.begin(); it!=table_inputs.end(); it++){
		cout << it->first << " " << it->second << endl;
		if(it->second == "disability"){
			readDisability(it->first);
			/*
			//Disability Table constructor call
			vector<DisabilityEntry> input = disabilityParse(it->first);
			distbl(input);
			*/
		}
		else if(it->second == "age"){
			readAge(it->first);
		}
		else if(it->second == "geography"){
			readGeog(it->first);
		}
	}

	//Get first 4 lines and do nothing with them
	getline(file,line);
	getline(file,line);
	getline(file,line);
	getline(file,line);

	//Declare regex patterns
	regex insert("INSERT"), update("UPDATE"), select("SELECT");
	regex write("WRITE"), remove("DELETE"), display("DISPLAY");
	regex geography("geography"), age("age"), disability("disability");

	while(getline(file,line)){
		if(regex_match(line,write)){ //Call write function from every table

		}
		else if(regex_match(line,display)){ //Call display fucntion from every table
			cout << "DISPLAY" << endl;
			//Need display tables functions
		}
		else if (regex_match(line,geography)){ //geography queries
				GeographyEntry temp = geog_query(line);

				if(regex_match(line,insert)){


				}

				else if(regex_match(line,update)){

				}

				else if(regex_match(line,select)){

				}

				else if(regex_match(line,remove)){

				}
		}

		else if (regex_match(line,age)){ //age queries
			AgeEntry temp = age_query(line);

					if(regex_match(line,insert)){

					}

					else if(regex_match(line,update)){

					}

					else if(regex_match(line,select)){

					}

					else if(regex_match(line,remove)){

					}
		}

		else if (regex_match(line,disability)){ //disability queries

			//Save each part of the scheme
			DisabilityEntry temp = disability_query(line);


			if(regex_match(line,insert)){
				distbl.insert(temp.geo_name, temp);

			}

			else if(regex_match(line,update)){

			}

			else if(regex_match(line,select)){

			}

			else if(regex_match(line,remove)){

			}
		}

	}


	cout << "Processing complete!" << endl;
	return 0;
}
