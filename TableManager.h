#ifndef MANAGER_H
#define MANAGER_H

#include <regex>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
//#include "disabilityTable.h"
//#include "ageTable.h"
//#include "geographyTable.h"
using namespace std;


DisabilityEntry disability_query(string input) {
  regex disa_query("(?:UPDATE|SELECT|DELETE|INSERT)\\(\\(\"(.*,.*)\",(.*),(.*),(.*),(.*),(.*),(.*)\\),(.*)\\)");
  smatch match;
  DisabilityEntry temp;
  if(regex_search(input, match, disa_query) == true) {
    temp.geo_name=match.str(1);
    if(match.str(2)=="*"){
      temp.hearing_disability = -1;   //If the data type is number, store "*" as value -1.
    }
    else{
      temp.hearing_disability = stoi(match.str(2));  //use stoi() to change string to int
    }

    if(match.str(3)=="*"){
      temp.vision_disability=-1;
    }
    else{
      temp.vision_disability = stoi(match.str(3));
    }

    if(match.str(4)=="*"){
      temp.cognitive_disability=-1;
    }
    else{
      temp.cognitive_disability = stoi(match.str(4));
    }

    if(match.str(5)=="*"){
      temp.ambulatory_disability=-1;
    }
    else{
      temp.ambulatory_disability = stoi(match.str(5));
    }

    if(match.str(6)=="*"){
      temp.self_care_disability=-1;
    }
    else{
      temp.self_care_disability = stoi(match.str(6));
    }

    if(match.str(7)=="*"){
      temp.independent_living_disability=-1;
    }
    else{
      temp.independent_living_disability = stoi(match.str(7));
    }
  }
  return temp;
}

AgeEntry age_query(string input) {
  regex age_query("(?:UPDATE|SELECT|DELETE|INSERT)\\(\\((.*),(.*),(.*),(.*)\\),(.*)\\)");
  smatch match;
  AgeEntry temp;

  if(regex_search(str, match, age_query) == true){
      temp.geo_geoid = match.str(1);
      if(match.str(2) == "*") {
        temp.under_5 = -1;
      }
      else{
        temp.under_5 = stoi(match.str(2));
      }

      if(match.str(3) == "*"){
        temp.under_18 = -1;
      }
      else{
        temp.under_18 = stoi(match.str(3));
      }

      if(match.str(4) == "*"){
        temp.over_65 = -1;
      }
      else{
        temp.over_65 = stoi(match.str(4));
      }
  }
  return temp;
}

GeographyEntry geog_query(string input){
  regex geog_query("(?:UPDATE|SELECT|DELETE|INSERT)\\(\\((.*),\"(.*,.*)\",(.*),(.*),(.*),(.*),(.*),(.*)\\),(.*)\\)");
  smatch match;
  GeographyEntry temp;

  if(regex_search(input, match, geog_query) == true){
    if(match.str(1) == "*"){
      temp.replan_id = -1;
    }
    else{
      temp.replan_id = stoi(match.str(1));
    }

    temp.geo_name = match.str(2);

    temp.geo_stusab = match.str(3);

    if(match.str(4)=="*"){
      temp.geo_sumlev = -1;
    }
    else{
      temp.geo_sumlev = stoi(match.str(4));
    }

    if(match.str(5) == "*"){
      temp.geo_state = -1;
    }
    else{
      temp.geo_state = stoi(match.str(5));
    }

    if(match.str(6)=="*"){
      temp.geo_county=-1;
    }
    else{
      temp.geo_county=stoi(match.str(6));
    }

    temp.geo_geoid = match.str(7);

    if(match.str(8)=="*"){
      temp.population=-1;
    }
    else{
      temp.population = stoi(match.str(8));
    }
  }
  return temp;
}

#endif /* end of include guard: MANAGER */
