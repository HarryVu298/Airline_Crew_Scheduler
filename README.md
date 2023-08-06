# Airline_Crew_Scheduler

Airline Crew Scheduler is an application developed by Harry Vu in 2023 to help airlines organize their crew schedules based on flight assignments. It provides an interactive menu-based system where the user can:

1. View a list of crew names.
2. View all flight locations.
3. View crews for a specific flight.
4. View flights for a specific crew member.

All data is sourced from the files Flights.txt and CrewSchedule.txt.

## Features:

1. Data Reading: Reads flight data from "Flights.txt" and crew data from "CrewSchedule.txt".
2. Data Display: Efficiently displays crew names, flight locations, and more as per user request.
3. Flexibility: Uppercase and lowercase input for flight destinations and crew names are supported to ensure user flexibility.
4. Feasibility Check: Checks if a given flight schedule for a crew member is feasible or not.
   
## File Structure:

* main.cpp: The entry point for the application. Contains the main loop for the interactive menu system.
* functions.cpp: Contains the function implementations required for reading files, displaying data, and other utility tasks.
* functions.h (not shown in the provided code): Header file declaring the functions and data structures used in functions.cpp.
  
## Setup:

1. Ensure you have a C++ compiler.
2. Compile the project using the command (or use your IDE's build system):
* g++ main.cpp functions.cpp -o AirlineCrewScheduler *
3. Run the compiled executable.
4. Ensure Flights.txt and CrewSchedule.txt are in the same directory as the executable or adjust the paths in the code accordingly.

## Usage:

Run the compiled executable and follow the on-screen prompts. Choose the required options from the menu to interact with the application.

## License:
This project is copyrighted by Harry Vu, 2023.

