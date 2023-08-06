// Copyright 2023, Harry Vu
// Purpose: This program read from 2 files
// to make An Airline Crew Scheduling Application to do
// the following options in the menu
// Date: Mar 8, 2023
// Author

// trial #
// 1: First submission to see the test case
// 2: Modifying the std::cout statements of
// printMenu method, there are some typos
// 3: Fixing the issue of missing 1 end of line when doing the option 3 and 4
// 4: Deleting the extra space in the std::cout
// statement, and going to next line
// after priting "Bye!"
// 5: Adding comments for main.cpp and functions.cpp,
// put the printMenu() into the loop for optimization

// Part 2 Coding trail
// 1: Change the print flight location statements
// (eliminating extra space that is not needed)
// 2: put another endl for printCrewNames
// 3: Add comments
// 4: fix base on cpplint

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "./functions.h"



int main() {
  // This vector is used to store the information of crews: name and schedule
  vector<pair<string, string> > crews;
  // This vector is used to store the infomation
  // of flights: origin and destination
  vector<pair<string, string> > flights;
  // This set is used to store the flight locations
  set<string> locations;

  // This method reads the flights from "Flights.txt"
  readFLights(flights, locations);

  // This method reads the crews info from "CrewSchedule.txt"
  readCrew(crews);

  // This is the loop to see what is the option that
  // the user choose, the loop only terminates when
  // user pick -1
  while (true) {
    // Print the menu
    printMenu();
    // Get the option choice from the user
    int choice;
    std::cin >> choice;

      switch (choice) {
         // List crew names option
         case 1:
            // print crew names
            printCrewNames(crews);
            break;
         // List all flight locations option
         case 2:
            printFlightLocations(locations);
            break;
         // List crews for the flight option
         case 3:
            // Print the flight locations before
            // letting the user choose the flight
            // to show crews
            printFlightLocations(locations);
            // Method to print all the crews for the flight (if applicable)
            case3(crews, flights, locations);
            break;
         // List flights for the crew
         case 4:
            // Method to list all flights
            // of crew and see whether if
            // it is plausible
            case4(crews, flights);
            break;
         // Exit the program option
         case -1:
            std::cout << "Bye!\n";
            return 0;
            break;
         // if the choice is not valid
         default:
            std::cout << "The wrong choice!!!\n\n";
            break;
      }

  // if the program is not terminate, request
  // the user to press enter before priting out
  // the menu again
  std::cout << "to continue, press enter...";
  std::cin.ignore();
  std::cin.get();
  // after pressing enter, continue the loop
  }

  return 0;
}
