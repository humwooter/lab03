#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"

class demogState {

public:
  friend std::ostream& operator<<(std::ostream &out, const demogState &SD);

  demogState() {
    name = "";
    numCounties = 0;
    PopOver65 = 0.0;
    PopUnder18 = 0.0;
    PopUnder5 = 0.0;
    PopBelowPoverty = 0.0;
    popBA = 0.0;
    popHS = 0.0;
    totalPop = 0.0;
  }

  string name;
  int numCounties;
  
  double PopOver65;
  double PopUnder18;
  double PopUnder5;
  double PopBelowPoverty;
  double popBA;
  double popHS;

  double totalPop; 
};
#endif
