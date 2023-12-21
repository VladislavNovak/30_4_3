#include <iostream>
#include <map>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "constants.h"
#include "cpr_requests.h"

using std::cout;
using std::endl;
using std::string;

using json = nlohmann::json;

int main() {
    std::map<string, string> payload{{"one", "1"}, {"two", "2"}, {"three", "3"}};

    // ---

    asyncGetRequest(payload);
    asyncPostRequest(payload);

    return 0;
}