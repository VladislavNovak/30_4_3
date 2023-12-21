#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include "headers/constants.h"
#include "headers/utilities.h"
#include "headers/cpr_requests.h"

using std::cout;
using std::endl;
using std::string;

using json = nlohmann::json;

int main() {
    std::map<string, string> payload;

    cout << "About: enter one of the keywords" << endl;
    cout << "   " << menuTitle[static_cast<int>(RequestType::GET)] << "  - to make a request" << endl;
    cout << "   " << menuTitle[static_cast<int>(RequestType::POST)] << " - to make a request" << endl;
    cout << "   exit - to terminate the program" << endl;

    while (true) {
        string key;
        string value;
        string command;

        cout << "Enter key:" << endl;
        std::getline(std::cin >> std::ws, key);

        // Если введено ключевое слово, то
        if (isIncludes(menuTitle, key)) { command = key; }
        else {
            cout << "Enter value:" << endl;
            std::getline(std::cin >> std::ws, value);

            // Если введено ключевое слово, то
            if (isIncludes(menuTitle, value)) { command = value; }
        }

        // Если команда введена, то
        if (!command.empty()) {
            if (command == menuTitle[static_cast<int>(RequestType::GET)]) {
                // Повторим процесс, если данных пока нет
                if (payload.empty()) {
                    cout << "No data yet. Try again" << endl;
                    continue;
                }
                asyncGetRequest(payload);
            }
            else if (command == menuTitle[static_cast<int>(RequestType::POST)]) {
                if (payload.empty()) {
                    cout << "No data yet. Try again" << endl;
                    continue;
                }
                asyncPostRequest(payload);
            }

            cout << "See you later" << endl;
            break;
        }

        // Если не было ни одной команды, то заполняем данные
        addEntryToMap(std::make_pair(key, value), payload);
    }

    return 0;
}