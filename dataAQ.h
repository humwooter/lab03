#ifndef DATAAQ_H
#define DATAAQ_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
//#include <map>
#include "demogState.h"

/*
  data aggregator and query for testing
*/
class dataAQ {
public:
  dataAQ() {};

  /* necessary function to aggregate the data - this CAN and SHOULD vary per
     student - depends on how they map, etc. */
  void createStateData(std::vector<shared_ptr<demogData>> theData);

  //return the name of the state with the largest population under age 5
  string youngestPop(); 

  //return the name of the state with the largest population under age 18
  string teenPop(); 
  //return the name of the state with the largest population over age 65
  string wisePop(); 
  //return the name of the state with the largest population who did not finish high school
  string underServeHS(); 
  //return the name of the state with the largest population who completed college
  string collegeGrads(); 
  //return the name of the state with the largest population below the poverty line
  string belowPoverty(); 
  void setAllStateData(map<string, demogState> stateData) {allStateData = stateData;}
  //getter given a state name return a pointer to demogState data
  shared_ptr<demogState> getStateData(string stateName) { return make_shared<demogState>(allStateData[stateName]);  };
  friend std::ostream& operator<<(std::ostream &out, const dataAQ &allStateData);
  vector<string> states;
  //core data private for dataAQ
private:
  
  map<string, demogState> allStateData;
  //vector<string> states;
  //const int numStates; 
       //Decide how to aggregate the data into a map ADD here

};
#endif
