#include "effectsplugin_plugin.h"
#include "blur.h"
#include "colorOverlay.h"
#include "dropshadow.h"
#include <qqml.h>

void EffectsPluginPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<DropShadow>(uri, 1, 0, "DropShadow");
    qmlRegisterType<Blur>(uri, 1, 0, "Blur");
    qmlRegisterType<ColorOverlay>(uri, 1, 0, "ColorOverlay");
}


