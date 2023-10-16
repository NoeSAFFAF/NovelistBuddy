#include "ChatGPTClient.h"

#include <curl/curl.h>
#include <iostream>

ChatGPTClient::ChatGPTClient(const std::string& apiKey) : _apiKey(apiKey) 
{
}

std::wstring ChatGPTClient::generateResponse(const std::wstring& prompt) 
{
    std::wstring response;
    std::string responseSimple;

    CURL* curl = curl_easy_init();
    if (curl) 
    {
        struct curl_slist* headers = NULL;

        std::string authHeader = "Authorization: Bearer " + _apiKey;
        headers = curl_slist_append(headers, authHeader.c_str());

        std::string test = "Hello chatgpt";
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/engines/gpt-3.5-turbo/completions");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, test.c_str());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &ChatGPTClient::onResponseReceived);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseSimple);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "cURL failed: %s\n", curl_easy_strerror(res));
        }
        else {
            // Print the response
            std::cout << "Response: " << responseSimple << std::endl;
        }

        // Clean up
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    return response;
}

std::wstring ChatGPTClient::getFinalPrompt(const std::wstring& prompt)
{
    std::wstring finalPrompt = L"Here is the context :\n" + _promptContext + L"\n" + L"Here is my request :\n" + prompt;
    return finalPrompt;
}

size_t ChatGPTClient::onResponseReceived(void* contents, size_t size, size_t nmemb, std::string* output)
{
    size_t total_size = size * nmemb;
    std::string data(static_cast<char*>(contents), total_size / sizeof(char));
    output->append(data);
    return total_size;
}