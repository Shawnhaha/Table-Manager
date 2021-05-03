/* Read 3 tables and get initial data */
#ifndef READTABLE_H
#define READTABLE_H

#include <regex>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
//#include "disabilityTable.h"
//#include "ageTable.h"
//#include "geographyTable.h"
using namespace std;

void readDisability(string table_name){
  cout << "Processing disability table." << endl;

  ifstream file;
  string line;

  file.open(table_name);
  //Get first 2 lines and do nothing with them
	getline(file,line);
	getline(file,line);

  while(getline(file,line)){
    regex disa_query("\"(.*,.*)\",(.*),(.*),(.*),(.*),(.*),(.*)");
    smatch match;
    DisabilityEntry temp;
    DisabilityTable distbl;

    if(regex_search(input, match, disa_query) == true) {
      temp.geo_name=match.str(1);
      temp.hearing_disability=stoi(match.str(2));   //use stoi() to change string to int
      temp.vision_disability=stoi(match.str(3));
      temp.cognitive_disability=stoi(match.str(4));
      temp.ambulatory_disability=stoi(match.str(5));
      temp.self_care_disability=stoi(match.str(6));
      temp.independent_living_disability=stoi(match.str(7));

      distbl.insert(temp.geo_name, temp);
      cout << "Inserted (" << match.str(0) << ") into disability";
    }
  }
}

void readAge(string table_name){
  cout << "Processing age table." << endl;

  ifstream file;
  string line;

  file.open(table_name);
  //Get first 2 lines and do nothing with them
	getline(file,line);
	getline(file,line);

  while(getline(file,line)){
    regex age_query("(.*),(.*),(.*),(.*)");
    smatch match;
    AgeEntry temp;
    AgeTable agetbl;

    if(regex_search(str, match, age_query) == true){
      temp.geo_geoid = match.str(1);
      temp.under_5 = stoi(match.str(2));
      temp.under_18 = stoi(match.str(3));
      temp.over_65 = stoi(match.str(4));

      agetbl.insert(temp);
      cout << "Inserted (" << match.str(0) << ") into age";
    }
  }
}

void readGeog(string table_name){
  cout << "Processing geography table." << endl;

  ifstream file;
  string line;

  file.open(table_name);
  //Get first 2 lines and do nothing with them
	getline(file,line);
	getline(file,line);

  while(getline(file,line)){
    regex geog_query("(.*),\"(.*,.*)\",(.*),(.*),(.*),(.*),(.*),(.*)");
    smatch match;
    GeographyEntry temp;
    GeographyTable geotbl;

    if(regex_search(input, match, geog_query) == true){
      temp.replan_id = stoi(match.str(1));
      temp.geo_name = match.str(2);
      temp.geo_stusab = match.str(3);
      temp.geo_sumlev = stoi(match.str(4));
      temp.geo_state = stoi(match.str(5));
      temp.geo_county = stoi(match.str(6));
      temp.geo_geoid = match.str(7);
      temp.population = stoi(match.str(8));

      agetbl.insert(temp);
      cout << "Inserted (" << match.str(0) << ") into geography";
    }
  }
}

#endif
