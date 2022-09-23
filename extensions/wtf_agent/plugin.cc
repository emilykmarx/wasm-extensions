#include "extensions/wtf_agent/plugin.h"

static RegisterContextFactory register_WTFAgent(
    CONTEXT_FACTORY(PluginContext), ROOT_FACTORY(PluginRootContext));

bool PluginRootContext::onConfigure(size_t) { return true; }
