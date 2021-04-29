#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/
class demogData {
public:

  demogData(string inN, string inS, double in65, double in18,
            double in5) :
    name(inN), state(inS), popOver65(in65), popUnder18(in18),
    popUnder5(in5), popBA(0.0), popHS(0.0), popUnderPoverty(0.0), pop14(0) {
    }
  demogData(string inN, string inS, double in65, double in18,
            double in5, int totalPop) :
    name(inN), state(inS), popOver65(in65), popUnder18(in18),
    popUnder5(in5), popBA(0.0), popHS(0.0), popUnderPoverty(0.0), pop14(totalPop) {
    }

  demogData(string inN, string inS, double in65, double in18,
              double in5, double BAup, double HSup) :
      name(inN), state(inS), popOver65(in65), popUnder18(in18),
      popUnder5(in5), popBA(BAup), popHS(HSup), popUnderPoverty(0.0), pop14(0.0) {
    }

    demogData(string inN, string inS, double in65, double in18,
              double in5, double BAup, double HSup, double povPop, double totalPop) :
      name(inN), state(inS), popOver65(in65), popUnder18(in18),
      popUnder5(in5), popBA(BAup), popHS(HSup), popUnderPoverty(povPop), pop14(totalPop) {
    }

    string getName() { return name; }
    string getState() { return state; }
    double getpopOver65() { return popOver65; }
    double getpopUnder18() { return popUnder18; }
    double getpopUnder5() { return popUnder5; }
    double getBAup() { return popBA; }
    double getHSup() { return popHS; }
    int getPop() { return pop14; }

  int getpopOver65Count() const { return (int)(((popOver65/100.0) * pop14) + 0.5); }
  int getpopUnder18Count() const { return (int)(((popUnder18/100.0) * pop14) + 0.5); }
  int getpopUnder5Count() const { return (int)(((popUnder5/100.0) * pop14) + 0.5); }
  int getBAupCount() const { return (int)(((popBA/100.0) * pop14) + 0.5); }
  int getHSupCount() const { return (int)(((popHS/100.0) * pop14) + 0.5); }
  double getPopUnderPovCount() const { return int(((popUnderPoverty/100.0)*pop14) + 0.5); }

    friend std::ostream& operator<<(std::ostream &out, const demogData &DD);
  
private:
    const string name;
    const string state;
    const double popOver65;
    const double popUnder18;
    const double popUnder5;
    const double popBA;
    const double popHS;
    const double popUnderPoverty;
    const double pop14;
};
#endif
