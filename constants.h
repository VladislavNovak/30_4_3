#ifndef INC_30_4_3_CONSTANTS_H
#define INC_30_4_3_CONSTANTS_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

const string ROOT = R"(https://httpbin.org)";

enum class RequestType { GET, POST };

const vector<string> requestTypeTitles{"get", "post", "exit"};

#endif //INC_30_4_3_CONSTANTS_H
