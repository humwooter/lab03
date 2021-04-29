#include "dataAQ.h"
#include "parse.h"
#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Testing state data aggregation query..." << endl;

	dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<demogData>> theData = read_csv(
            "county_demographics.csv", DEMOG);

    theAnswers.createStateData(theData);

    string youngestPop = theAnswers.youngestPop();
  	ASSERT_EQUALS("UT",youngestPop);

  	string bachelors = theAnswers.collegeGrads();
  	ASSERT_EQUALS("DC",bachelors);

    // cout << "*** the state that needs the most pre-schools**" << endl;
    // string needPK = theAnswers.youngestPop();
    // demogState stateMostUnder5 = *(theAnswers.getStateData(needPK));
    // cout << stateMostUnder5;

    // cout <<"*** the state that needs the most high schools**" << endl;

    // string mostHS = theAnswers.teenPop();
    // demogState stateMostHS = *(theAnswers.getStateData(mostHS));
    // cout << stateMostHS;

    // cout <<"*** the state that needs the most vaccines**" << endl;

    // string mostOver65 = theAnswers.wisePop();
    // demogState stateMostVaccines = *(theAnswers.getStateData(mostOver65));
    // cout << stateMostVaccines;

    // cout <<"*** the state that needs the most help with education**" << endl;

    // string leastHS = theAnswers.underServeHS();
    // demogState stateLeastHS = *(theAnswers.getStateData(leastHS));
    // cout << stateLeastHS;

    // cout <<"*** the state with most college grads**" << endl;

    // string mostBA = theAnswers.collegeGrads();
    // demogState stateMostBA = *(theAnswers.getStateData(mostBA));
    // cout << stateMostBA;

    // cout <<"*** the state with largest percent of the population below the poverty line**" << endl;

    // string mostPoverty = theAnswers.belowPoverty();
    // demogState stateMostPoverty = *(theAnswers.getStateData(mostPoverty));
    // cout << stateMostPoverty;

  return 0;
}
