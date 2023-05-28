//
// Created by Piotr Szczypior on 09/04/2023.
//

#include <limits>
#include "Utils.h"

using namespace std;

int Utils::get_input() {
    cin.clear();
    string input;
    cin >> input;
    return stoi(input);
}

void Utils::press_any_to_continue() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Press enter to continue." << endl;
    cin.get();
}

void Utils::clear_console() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
