#pragma once
#include <string>

class ChatGPTClient 
{
public:
    ChatGPTClient(const std::string& apiKey);

    inline std::wstring setContext(const std::wstring& promptContext) { _promptContext = promptContext; };
    std::wstring generateResponse(const std::wstring& prompt);

private:
    std::string _apiKey;
    std::wstring _promptContext;

    std::wstring getFinalPrompt(const std::wstring& prompt);
    static size_t onResponseReceived(void* contents, size_t size, size_t nmemb, std::string* output);
};