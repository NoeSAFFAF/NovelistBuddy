#include <iostream>

#include "Utils\IO\IOFileHelper.h"
#include "Client\ChatGPTClient.h"

int main()
{
	std::string apiKey = "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";
	
	ChatGPTClient chatGPTClient(apiKey);
	
	std::wstring response = chatGPTClient.generateResponse(L"Hello my friend");

	IOFileHelper ioFileHelper;
	ioFileHelper.writeIntoFile("output1.txt", response);

    while (true) 
	{

    }
	return 0;
}
