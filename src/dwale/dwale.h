/**********************************************************\

  Auto-generated dwale.h

  This file contains the auto-generated main plugin object
  implementation for the dwale project

\**********************************************************/
#ifndef H_dwalePLUGIN
#define H_dwalePLUGIN

#include "PluginWindow.h"
#include "PluginEvents/MouseEvents.h"
#include "PluginEvents/AttachedEvent.h"

#include "PluginCore.h"

extern "C" {

    
}

FB_FORWARD_PTR(dwale)
class dwale : public FB::PluginCore
{
public:
    static void StaticInitialize();
    static void StaticDeinitialize();

public:
    dwale();
    virtual ~dwale();

public:
    void onPluginReady();
    void shutdown();
    virtual FB::JSAPIPtr createJSAPI();
    // If you want your plugin to always be windowless, set this to true
    // If you want your plugin to be optionally windowless based on the
    // value of the "windowless" param tag, remove this method or return
    // FB::PluginCore::isWindowless()
    virtual bool isWindowless() { return false; }

    BEGIN_PLUGIN_EVENT_MAP()
    END_PLUGIN_EVENT_MAP()
};


#endif

