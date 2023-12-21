#include "cpr_requests.h"

void asyncRequest(RequestType requestType,
                  const cpr::Url &URL,
                  const std::map<string, string> &payload,
                  const string &responseType) {
    // Позволяет программе дождаться выполнения запроса
    bool isRun = true;

    // Используем функцию обратного вызова.
    auto callback{[&isRun, &responseType](const cpr::Response &r) {
        if (r.status_code == 200) {
            cout << "Request completed in " << r.elapsed << endl;

            // Разбираем тело ответа. После этого сможем получать доступ к каждому элементу json
            json jDoc(json::parse(r.text));
            // cout << "CONTENT TEST:" << endl;
            // cout << jDoc.dump(2) << endl;

            try {
                auto jUrl{jDoc.at("url").get<string>()};
                cout << "url content-> " << jUrl << endl;

                auto data{jDoc.at(responseType).get<std::map<string, string>>()};
                cout << responseType << " content->" << endl;
                for (const auto &[first, second] : data) {
                    cout << std::setw(10) << std::left << first << ": " << second << endl;
                }
            }
            catch (json::exception &e) { cout << "Trouble" << endl;}
        }
        else if (r.status_code == 0) { std::cerr << r.error.message << endl; }
        else { cout << "Something wrong with status: " << r.status_code << endl; }

        // Ожидание можно завершать
        isRun = false;
    }};

    if (requestType == RequestType::GET) {
        // Конвертируем std::map в cpr::Parameters
        cpr::Parameters Params{};
        for (const auto &[first, second] : payload) {
            Params.Add({first, second});
        }
        // ---

        cout << "Loading..." << endl;
        cpr::GetCallback(callback, URL, Params);
    }
    else if (requestType == RequestType::POST) {
        cpr::Header Header{{"content-type", "application/json"}};
        // Конвертируем std::map в json просто передавая в конструктор
        json jPayload(payload);
        // Если бы данные пришли в виде объекта, то конвертация выглядела бы так:
        // json jPayload(json::object({ {"one", "1"}, {"two", "2"}, {"three", "3"} }));
        cpr::Body Body(jPayload.dump());
        // ---

        cout << "Loading..." << endl;
        cpr::PostCallback(callback, URL, Header, Body);

    }

    while (isRun) {}
}

void asyncPostRequest(const std::map<string, string> &payload) {
    RequestType type = RequestType::POST;
    cpr::Url URL{ROOT + R"(/post)"};
    string responseType = "json";

    asyncRequest(type, URL, payload, responseType);
}

void asyncGetRequest(const std::map<string, string> &payload) {
    RequestType type = RequestType::GET;
    cpr::Url URL{ROOT + R"(/get)"};
    string responseType = "args";

    asyncRequest(type, URL, payload, responseType);
}
