/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "demogState.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std; 

void dataAQ::createStateData(std::vector<shared_ptr<demogData>> theData) {
  map<string, demogState> stateData; 
  string state;
  vector<string> States;
  int popOver65Count;
  int popUnder18Count;
  int popUnder5Count;
  int countyPop;
  int HSupCount;
  int BAupCount;
  int popUnderPovertyCount;
  
  for (int i = 0; i < theData.size(); i++) {
    demogData currCounty = *(theData[i]);
    state = currCounty.getState();
    
    if (stateData.find(state) == stateData.end()) {
      stateData[state] = demogState();
      stateData[state].name = state;
    }
    if (find(States.begin(), States.end(), state) == States.end()) States.push_back(state);

    stateData[state].numCounties += 1;
    stateData[state].PopOver65 += currCounty.getpopOver65Count();
    stateData[state].PopUnder18 += currCounty.getpopUnder18Count();
    stateData[state].PopUnder5 += currCounty.getpopUnder5Count();
    stateData[state].PopBelowPoverty += currCounty.getPopUnderPovCount();
    stateData[state].popBA += currCounty.getBAupCount();
    stateData[state].popHS += currCounty.getHSupCount();
    stateData[state].totalPop += currCounty.getPop();

  }

  setAllStateData(stateData);
  states = States;
}

//return the name of the state with the largest population under age 5
string dataAQ::youngestPop() {
  string stateYoungestPop;
  double greatestPopUnder5 = 0.0; 
  for (int i = 0; i < states.size(); i++) {
    string state = states[i];
    double popUnder5 = allStateData[state].PopUnder5;
    double totalStatePop = allStateData[state].totalPop;
    double percentUnder5 = (popUnder5/totalStatePop)*100.0;

    if (percentUnder5 > greatestPopUnder5) {
      greatestPopUnder5 = percentUnder5;
      stateYoungestPop = state;
    }

  }
  return stateYoungestPop; 
} 

//return the name of the state with the largest population under age 18
string dataAQ::teenPop()  {
  string stateTeenPop;
  double greatestPopUnder18 = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popUnder18 = allStateData[state].PopUnder18;
    double totalStatePop = allStateData[state].totalPop;
    double percentUnder18 = (popUnder18/totalStatePop)*100.0;

    if (percentUnder18 > greatestPopUnder18) {
      greatestPopUnder18 = percentUnder18;
      stateTeenPop = state;
    }

  }
  return stateTeenPop;
 
}

//return the name of the state with the largest population over age 65
string dataAQ::wisePop()  {
  string stateWisePop;
  double greatestPopOver65 = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popOver65 = allStateData[state].PopOver65;
    double totalStatePop = allStateData[state].totalPop;
    double percentOver65 = (popOver65/totalStatePop)*100.0;

    if (percentOver65 > greatestPopOver65) {
      greatestPopOver65 = percentOver65;
      stateWisePop = state;
    }

  }
  return stateWisePop;
}

//return the name of the state with the largest population who did not receive high school diploma
string dataAQ::underServeHS() {
  string stateUnderServeHS;
  double greatestUnderServeHS = 100.0;
  for (int i = 0; i <  allStateData.size(); i++) {
    string state = states[i];
    double popHS = allStateData[state].popHS;
    double totalStatePop = allStateData[state].totalPop;
    double percentHSup = (popHS/totalStatePop)*100.0;

    if (percentHSup < greatestUnderServeHS) {
      greatestUnderServeHS = percentHSup;
      stateUnderServeHS = state;
    }

  }
  return stateUnderServeHS;
} 

//return the name of the state with the largest population who did receive bachelors degree and up
string dataAQ::collegeGrads() {
  string stateGreatestBA;
  double greatestBA = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popBA = allStateData[state].popBA;
    double totalStatePop = allStateData[state].totalPop;
    double percentBA = (popBA/totalStatePop)*100.0;

    if (percentBA > greatestBA) {
      greatestBA = percentBA;
      stateGreatestBA = state;
    }

  }
  return stateGreatestBA;
}

//return the name of the state with the largest population below the poverty line
string dataAQ::belowPoverty() {
  string stateGreatestBelowPov;
  double greatestBelowPov = 0.0;
  for (int i = 0; i <  states.size(); i++) {
    string state = states[i];
    double popBelowPov = allStateData[state].PopBelowPoverty;
    double totalStatePop = allStateData[state].totalPop;
    double percentBelowPov = (popBelowPov/totalStatePop)*100.0;

    if (percentBelowPov > greatestBelowPov) {
      greatestBelowPov = percentBelowPov;
      stateGreatestBelowPov = state;
    }

  }
  return stateGreatestBelowPov;
} 
