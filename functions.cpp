// Copyright 2023, Harry Vu
// Purpose: This is the functions methods file
// for the main.cpp
// Author: Harry Vu
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include "./functions.h"

void toUpper(std::string& str);

/**
 * This method is used to read the flights info from the "Flights.txt"
 * and put corresponding information into std::vector flights and locations
 * @param flights The pass by reference of flights std::vector
 * @param locations The pass by reference of std::set locations
*/
void readFLights(std::vector<std::pair<std::string,
    std::string> >& flights, std::set<std::string>& locations) {
    // Initialize input stream
    std::ifstream read("Flights.txt");

    // If there is error opening the input file
    if (!read.good()) {
        std::cout << "Could not open the input file(s)!!!\n";
        // exit with error
        exit(1);
    }

    // std::string to store the origin, and destination from the file
    std::string origin, destination;
    // read from the file until end of file
    while (read >> origin >> destination) {
        // put the flights info into the flights std::vector
        flights.push_back(make_pair(origin, destination));

        // add locations into the std::set
        locations.insert(origin);
        locations.insert(destination);
    }
    // close the file after finishing reading
    read.close();
}

/**
 * This method is used to read crews data from CrewSchedule.txt
 * and put relevant information into crews std::vector
 * @param crews Pass by reference of crews std::vector, holding crews info
*/
void readCrew(std::vector<std::pair<std::string, std::string> >& crews) {
    // initialize the input file reader stream
    std::ifstream read("CrewSchedule.txt");

    // If there is error opening the input file
    if (!read.good()) {
        std::cout << "Could not open the input file(s)!!!\n";
        // exit with error
        exit(1);
    }

    // std::string to hold value of name and schedule of crews
    std::string name, schedule;
    // Reading from the file until end of file
    while (read >> name >> schedule) {
        // put those info into the crews std::vectors
        crews.push_back(make_pair(name, schedule));
    }
    // close the file after finishing reading
    read.close();
}

/**
 * This method is used to print menu to the user
*/
void printMenu() {
    std::cout << "-----------------------------------"
         << "\nAirline Crew Scheduling Application\n"
         << "-----------------------------------\n"
         <<" 1 List crew names\n"
         << " 2 List all flight locations\n"
         << " 3 List crews for the flight\n"
         << " 4 List flights for the crew\n"
         << "-1 Exit\n"
         << "-----------------------------------\n"
         << "Enter your choice >> ";
}

/**
 * This method is used to print the crew names for option 1
 * @param crews the crews std::vector holding crews information: name and schedule
 * 
*/
void printCrewNames(std::vector<std::pair<std::string, std::string> >& crews) {
    std::cout << "--- Crew Names ---\n";
    // iterate through the std::vector and print
    // out to the console the all the name of the crews
    for (std::pair<std::string, std::string> cr : crews) {
        std::cout << cr.first << std::endl;
    }
    std::cout << std::endl;
}

/**
 * This method is used to print the all the flights location
 * for option 2 and option 3
 * @param locations the std::set of locations
*/
void printFlightLocations(std::set<std::string> locations) {
    std::cout << "--- Flight Locations ---\n";
            // List all the flight locations
            for (std::string s : locations) {
               std::cout << s << std::endl;
            }
            std::cout << std::endl;
}

/**
 * This method is for case 3 to print out all the crews
 * that work on the indicated flight
 * @param crews the std::vector holding crews name and schedule
 * @param flights the vetor holding flights origin and destination
 * @param location the std::set of locations
*/
void case3(std::vector<std::pair<std::string, std::string> >& crews,
    std::vector<std::pair<std::string, std::string> >& flights,
         std::set<std::string>& locations) {
    // Location of the chosen flight in the flights std::vector
    int pos;
    // std::string to store values of from and to cities
    std::string from, to;

    // Loop to force the user enter until
    // the 2 inputs are correct
    while (true) {
        // Get 2 cities from the user
        std::cout << "FROM >> ";
        std::cin >> from;
        std::cout << "TO >> ";
        std::cin >> to;

        // Not case-sensitive so turn
        // them into uppercase
        toUpper(from);
        toUpper(to);

        // If one out of 2 cities is not in the locations
        // std::set, there is no flights between them
        // require the user to input again
        if (locations.find(from) == locations.end()
            || locations.find(to) == locations.end()) {
            std::cout << "No flight was found!! Please try again...\n\n";
        } else {
            // if those 2 cities are in the location std::set,
            // try to see if there is a way to go from from to to
           auto it = find(flights.begin(), flights.end(), make_pair(from, to));
           if (it == flights.end()) {
            std::cout << "No flight was found!! Please try again...\n\n";
           } else {
            // If there is a flight alike the input, try to find
            // the location of flight in the flights std::vector
            pos = distance(flights.begin(), it);
            // Stop forstd::cing the user to reenter when the
            // 2 inputs are correct
            break;
           }
        }
    }
    std::cout << "---- Crew List ----" << std::endl;
    // Method to count how many crews work on this flight
    int count = 0;
    // Loop through every crew and their schedule
    for (std::pair<std::string, std::string> cr : crews) {
        // If they work on that flight
        if (cr.second.substr(pos, 1) == "1") {
            // Print their name
            std::cout << cr.first << std::endl;
            count++;
        }
    }
    std::cout << count << " crew(s) work(s) on the flight "
        << from << "-" << to << std::endl << std::endl;
}

/**
 * This method is used to make all std::string to uppercase
 * because we want the program to be not case-sensitive
 * @param str The std::string to be turn into uppercase
*/
void toUpper(std::string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}

/**
 * This is the method to check if the schedule is plausible
 * @param flight the scheduled flights of a crew
 * @param flights the flights data, holding origin and destination
 * @param count count how many flights this crew will work on
 * @return true if the schedule is plausible, false otherwise
*/
bool checkFeasible(std::string flight, std::vector<std::pair<std::string,
    std::string> >& flights, int& count) {
    // std::string to hold the previous flight's destination
    std::string prev = "";
    // Boolean to see if the schedule is plausible or not
    bool result = true;
    std::cout << "---- Assigned Flights ----\n";
    // Loop through the schedule of the crew
    for (int i = 0; i < flight.length(); i++) {
        // If they work on that flight, print out
        if (flight[i] == '1') {
            std::cout << flights[i].first << "-"
                << flights[i].second << std::endl;
            count++;
            // don't check for the first flight
            if (prev != "") {
                // If the origin of this flight is not
                // matching with the previous flight's location
                // then the schdule is not plausible
                if (flights[i].first != prev) {
                    result = false;
                }
            }
            // Update the previous flight's desination
            prev = flights[i].second;
        }
    }
    // return the result
    return result;
}

/**
 * This method is used to print all the flights of a crew and to
 * to see if it is plausible or not
 * @param crews std::vector holding crews info including name and schedule
 * @param flights std::vector holding flights info including origin and destination
*/
void case4(std::vector<std::pair<std::string, std::string> >& crews,
    std::vector<std::pair<std::string, std::string> >& flights) {
    // Name of the crew
    std::string name;
    // Boolean to see if the schedule is plasible or not
    bool feasible;
    // Count the number of flights crew is working on
    int count = 0;
    // Loop to force the user input
    // until the input is acceptable
    while (true) {
        // Get the crew name from the user
        std::cout << "Enter the crew name >> ";
        std::cin >> name;
        // make it uppercase
        toUpper(name);
        // boolean to see if the crew name is in the data
        bool found = false;
        // Loop through all the crew
        for (std::pair<std::string, std::string> cr : crews) {
            // If the crew is found
            if (cr.first == name) {
                found = true;
            } else {
                // continue looking
                continue;
            }
            // check to see if the schedule is plausible
            // And print out the schedule
            feasible = checkFeasible(cr.second, flights, count);
        }
        // If the crew is not found, make the user input again
        if (!found) {
            std::cout << "No record for " << name
                << ". Please try again..." << std::endl;
        } else {
            // break the loop when the user is found
            break;
        }
    }
    // If the crew have no flight
    if (count == 0) {
        std::cout << "No flight was assigned to " << name << " !!!\n\n";
    } else {
        // if the schedule is plausible
        if (feasible) {
            std::cout << "The flight sequence is feasible\n\n";
        } else {
            // if the schedule is not plausible
            std::cout << "The flight sequence is not feasible!!\n\n";
        }
    }
}
