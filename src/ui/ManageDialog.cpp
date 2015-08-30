#include "inc/ui/ManageDialog.hpp"
#include "ui_ManageDialog.h"

#include "inc/model/AlertModel.hpp"

#include <QDebug>

ManageDialog::ManageDialog(AlertModel*model, QWidget *parent) : QDialog(parent), _ui(new Ui::ManageDialog), _model(model) {
	_ui->setupUi(this);

	_ui->alertsListView->setModel(model);
	_ui->alertsListView->setCurrentIndex(model->index(0));
	updateAlertDetails(_ui->alertsListView->currentIndex());

	connect(_ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
	connect(_ui->alertsListView, &QListView::clicked, this, &ManageDialog::updateAlertDetails);
	connect(_ui->resetButton, &QPushButton::clicked, this, &ManageDialog::reset);
	connect(_ui->updateButton, &QPushButton::clicked, this, &ManageDialog::updateModel);
}

ManageDialog::~ManageDialog() {
	delete _ui;
}

void ManageDialog::updateAlertDetails(const QModelIndex &index) {
	QMap<int, QVariant> dataMap = _ui->alertsListView->model()->itemData(index);
	_ui->labelEdit->setText(dataMap.value(AlertModel::NameRole).toString());
	_ui->descriptionEdit->setText(dataMap.value(AlertModel::DesciptionRole).toString());
	_ui->repetitiveCheckbox->setChecked(dataMap.value(AlertModel::RepetitiveRole).toBool());
}

void ManageDialog::reset() {
	updateAlertDetails(_ui->alertsListView->currentIndex());
}

void ManageDialog::updateModel() {
	QMap<int, QVariant> dataMap;

	dataMap.insert(AlertModel::RepetitiveRole, _ui->repetitiveCheckbox->isChecked());
	dataMap.insert(AlertModel::NameRole, _ui->labelEdit->text());
	dataMap.insert(AlertModel::DesciptionRole, _ui->descriptionEdit->text());

	_model->setItemData(_ui->alertsListView->currentIndex(), dataMap);
}
