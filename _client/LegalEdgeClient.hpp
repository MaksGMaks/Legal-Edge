#pragma once

class UiManager;
class ApiManager;
class Reader;

class LegalEdgeClient
{
public:
    LegalEdgeClient(UiManager &uiManager, ApiManager &apiManager);
    ~LegalEdgeClient();

    void start();

private:
    // --- UI ---
    UiManager &m_uiManager;
    ApiManager &m_apiManager;

    Reader *read;
};