#include "cpr_requests.h"

void asyncGetRequest(const string &root, const cpr::Parameters &payload) {
    string METHOD = R"(/get)";
    cpr::Url URL{root + METHOD};

    // Позволяет программе дождаться выполнения запроса
    bool isRun = true;

    // Используем функцию обратного вызова.
    auto callback{[&isRun](const cpr::Response &r) {
        if (r.status_code == 200) {
            cout << "Request completed in " << r.elapsed << endl;

            json jDoc(json::parse(r.text));
            // cout << "CONTENT TEST:" << endl;
            // cout << jDoc.dump(2) << endl;

            try {
                auto jUrl{jDoc.at("url").get<string>()};
                cout << "URL RESPONSE-> " << jUrl << endl;

                auto jArgs{jDoc.at("args").get<std::map<string, string>>()};
                cout << "ARGS RESPONSE ->" << endl;
                for (const auto &[first, second] : jArgs) {
                    cout << first << ": " << second << endl;
                }
            }
            catch (json::exception &e) { cout << "Trouble" << endl;}
        }
        else if (r.status_code == 0) { std::cerr << r.error.message << endl; }
        else { cout << "Something wrong with status: " << r.status_code << endl; }

        // Ожидание можно завершать
        isRun = false;
    }};

    cout << "Loading..." << endl;
    cpr::GetCallback(callback, URL, payload);

    while (isRun) {}
}
