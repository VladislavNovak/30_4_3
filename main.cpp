#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "cpr_requests.h"

using std::cout;
using std::endl;
using std::string;

using json = nlohmann::json;

int main() {
    const string ROOT = R"(https://httpbin.org)";
    cpr::Parameters Params{{"cat", "meow"}, {"dog", "bark"}};

    // ---

    asyncGetRequest(ROOT, Params);

    return 0;
}
