#include "inc/ui/ManageDialog.hpp"
#include "ui_ManageDialog.h"

#include "inc/model/AlertModel.hpp"

#include <QDebug>

ManageDialog::ManageDialog(AlertModel*model, QWidget *parent) : QDialog(parent), _ui(new Ui::ManageDialog) {
    _ui->setupUi(this);

    connect(_ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(_ui->alertsListView, &QListView::clicked, this, &ManageDialog::updateAlertDetails);

    _ui->alertsListView->setModel(model);
    _ui->alertsListView->setCurrentIndex(model->index(0));
}

ManageDialog::~ManageDialog() {
    delete _ui;
}

void ManageDialog::updateAlertDetails(const QModelIndex &index) {
    _ui->labelEdit->setText(index.data().toString());
}
