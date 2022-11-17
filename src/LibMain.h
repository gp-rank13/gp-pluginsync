#pragma once

#include "gigperformer/sdk/GPMidiMessages.h"
#include "gigperformer/sdk/GPUtils.h"
#include "gigperformer/sdk/GigPerformerFunctions.h"
#include "gigperformer/sdk/GigPerformerAPI.h"
#include "gigperformer/sdk/types.h"

class LibMain : public gigperformer::sdk::GigPerformerAPI
{
  public:
    explicit LibMain(LibraryHandle handle) : GigPerformerAPI(handle) { }
    ~LibMain() override { }

    void OnRackspaceActivated() override;
    void OnVariationChanged(int oldIndex, int newIndex) override;
    void Initialization() override;
    void SyncPlugins();
    std::string GetProductDescription() override;
};
