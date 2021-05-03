#include"read.h"
using namespace std;

vector<pair<string,string>> readDoc::table_input(string fname){
    ifstream fin;
    string str, line;
    stringstream data;
    vector<string> dkfs;
    vector<pair<string,string>> lines;

    //Reading in tables
    fin.open(fname);
    for(int i=0; i<2; i++){
      dkfs.clear();
      getline(fin, line); //Read first line
      data.str(line); //Create stringstream from line
      while(getline(data,str," ")) { //Split line by spaces
         dkfs.push_back(str);
      }
      //First in pair is file name for that tables
      //Second is the name of the table
      lines.push_back(pair<string,string> (dkfs.at(0),dkfs.at(1));
    }
    return lines;
}
