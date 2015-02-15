#ifndef EFFECTSPLOGIN_PLUGIN_H
#define EFFECTSPLOGIN_PLUGIN_H

#include <QQmlExtensionPlugin>
/*!
 * \brief The EffectsPluginPlugin class, it register the other classes to be used in Qml.
 */
class EffectsPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    /*!
     * \brief registerTypes, function to register the classes
     * \param uri
     */
    void registerTypes(const char *uri);
};

#endif // EFFECTSPLOGIN_PLUGIN_H

