#pragma once

class UiManager;

class LegalEdgeClient
{
public:
    LegalEdgeClient(UiManager &uiManager);
    ~LegalEdgeClient();

    void start();

private:
    // --- UI ---
    UiManager &m_uiManager;
};