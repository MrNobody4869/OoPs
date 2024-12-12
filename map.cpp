#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Declare a map to store state names and their populations
    map<string, int> statePopulation;

    // Populate the map with some state names and populations
    statePopulation["Maharashtra"] = 39538223;
    statePopulation["Tamil Nadu"] = 29145505;
    statePopulation["Rajasthan"] = 21538187;
    statePopulation["Odisha"] = 20201249;
    statePopulation["Kerala"] = 12812508;
    statePopulation["Telangana"] = 12812508;
    statePopulation["Assam"] = 11799448;
    statePopulation["Jharkhand"] = 10711908;
    statePopulation["Karnataka"] = 10439388;
    statePopulation["Gujarat"] = 10077331;
    statePopulation["Punjab"] = 9288994;
    cout << "State population database initialized.\n";

    while (true) {
        // Prompt the user to enter a state name
        string stateName;
        cout << "Enter the name of a state (or type 'exit' to quit): ";
        getline(cin, stateName);

        // Exit the loop if the user types "exit"
        if (stateName == "exit") {
            break;
        }

        // Search for the state in the map
        auto it = statePopulation.find(stateName);

        // Display the population if the state is found
        if (it != statePopulation.end()) {
            cout << "The population of " << stateName << " is " << it->second << ".\n";
        } else {
            cout << "State not found in the database.\n";
        }
    }

    cout << "Exiting program. Thank you!\n";

    return 0;
}
