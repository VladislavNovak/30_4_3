#ifndef INC_30_4_3_CPR_REQUESTS_H
#define INC_30_4_3_CPR_REQUESTS_H

#include <iostream>
#include <map>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include "constants.h"

using std::cout;
using std::endl;
using std::string;
using json = nlohmann::json;

// Вызывается опосредованно через asyncGetRequest или asyncPostRequest
void asyncRequest(RequestType, const cpr::Url &, const std::map<string, string> &, const string &);

void asyncGetRequest(const std::map<string, string> &payload);

void asyncPostRequest(const std::map<string, string> &payload);

#endif //INC_30_4_3_CPR_REQUESTS_H
