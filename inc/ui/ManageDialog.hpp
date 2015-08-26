#ifndef MANAGEDIALOG_HPP
#define MANAGEDIALOG_HPP

#include <QDialog>

namespace Ui {
    class ManageDialog;
}

class AlertModel;

class ManageDialog : public QDialog {
    Q_OBJECT

public:
    explicit ManageDialog(AlertModel *model, QWidget *parent = 0);
    ~ManageDialog();

private slots:
    void updateAlertDetails(const QModelIndex &index);

private:
    Ui::ManageDialog *_ui;
};

#endif // MANAGEDIALOG_HPP
