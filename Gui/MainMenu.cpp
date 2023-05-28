//
// Created by Piotr Szczypior on 28/05/2023.
//

#include "MainMenu.h"
#include "ShortestPathMenu.h"
#include "MinimumSpanningMenu.h"
#include "Utils/Utils.h"

void MainMenu::menu() {
    while (true) {
        cout << "Select problem:" << endl;
        cout << "   1. Problem - shortest graph path" << endl;
        cout << "   2. Problem - minimal spinning tree" << endl;
        cout << "   3. Exit" << endl << endl;
        cout << "Choice: ";
        int choice;
        choice = Utils::get_input();
        switch (choice) {
            case 1:
                Utils::clear_console();
                ShortestPathMenu::menu();
                break;
            case 2:
                Utils::clear_console();
                MinimumSpanningMenu::menu();
                break;
            case 3:
                break;
            default:
                cout << "Wrong choice!" << endl;
                break;
        }
    }
}
