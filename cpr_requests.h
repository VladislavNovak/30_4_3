#ifndef INC_30_4_3_CPR_REQUESTS_H
#define INC_30_4_3_CPR_REQUESTS_H

#include <iostream>
#include <map>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using std::cout;
using std::endl;
using std::string;
using json = nlohmann::json;

void asyncGetRequest(const string &root, const cpr::Parameters &payload);

#endif //INC_30_4_3_CPR_REQUESTS_H
