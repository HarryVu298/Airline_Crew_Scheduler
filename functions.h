#ifndef FUNCTIONS_H
#define FUNCTIONS_H


using namespace std;

#endif  // FUNCTIONS_H
void readFLights(vector<pair<string, string> >& flights, set<string>& locations);
void readCrew(vector<pair<string, string> >& crews);
void printMenu();
void printCrewNames(vector<pair<string, string> >& crews);
void printFlightLocations(set<string> locations);
void case3(vector<pair<string, string> >& crews, vector<pair<string, string> >& flights, set<string>& locations);
void case4(vector<pair<string, string> >& crews, vector<pair<string, string> >& flights);
