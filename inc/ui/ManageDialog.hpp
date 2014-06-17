#ifndef __MANAGE_DIALOG_HPP__
#define __MANAGE_DIALOG_HPP__

#include <QtQuick/QQuickView>

class AAlert;
class AlertManager;

class ManageDialog : public QQuickView {
public:
    ManageDialog(AlertManager* manager);
};

#endif // __MANAGE_DIALOG_HPP__
