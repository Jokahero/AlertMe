#include "inc/ui/ManageDialog.hpp"
#include "ui_ManageDialog.h"

#include "inc/model/AlertModel.hpp"

ManageDialog::ManageDialog(AlertModel*model, QWidget *parent) : QDialog(parent), _ui(new Ui::ManageDialog), _model(model) {
	_ui->setupUi(this);

	_ui->alertsListView->setModel(model);
	_ui->alertsListView->setCurrentIndex(model->index(0));
	refreshDetails();

	connect(_ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
	connect(_ui->alertsListView, &QListView::clicked, this, &ManageDialog::updateAlertDetails);
	connect(_ui->resetButton, &QPushButton::clicked, this, &ManageDialog::reset);
	connect(_ui->updateButton, &QPushButton::clicked, this, &ManageDialog::updateModel);

	connect(_ui->labelEdit, &QLineEdit::textChanged, this, &ManageDialog::onLabelChanged);
	connect(_ui->descriptionEdit, &QLineEdit::textChanged, this, &ManageDialog::onDescriptionChanged);
	connect(_ui->repetitiveCheckbox, &QCheckBox::toggled, this, &ManageDialog::onRepetitiveChanged);

	connect(_ui->removeButton, &QPushButton::clicked, this, &ManageDialog::removeAlert);
}

ManageDialog::~ManageDialog() {
	delete _ui;
}

void ManageDialog::updateAlertDetails(const QModelIndex &index) {
	QMap<int, QVariant> dataMap = _ui->alertsListView->model()->itemData(index);
	_ui->labelEdit->setText(dataMap.value(AlertModel::NameRole).toString());
	_ui->descriptionEdit->setText(dataMap.value(AlertModel::DesciptionRole).toString());
	_ui->repetitiveCheckbox->setChecked(dataMap.value(AlertModel::RepetitiveRole).toBool());

	_labelChanged = false;
	_descriptionChanged = false;
	_repetitiveChanged = false;

	updateButtonAvailability();
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

void ManageDialog::onLabelChanged() {
	_labelChanged = _ui->labelEdit->text() != _model->data(_ui->alertsListView->currentIndex(), AlertModel::NameRole).toString();
	updateButtonAvailability();
}

void ManageDialog::onDescriptionChanged() {
	_descriptionChanged = _ui->descriptionEdit->text() != _model->data(_ui->alertsListView->currentIndex(), AlertModel::DesciptionRole).toString();
	updateButtonAvailability();
}

void ManageDialog::onRepetitiveChanged() {
	_repetitiveChanged = _ui->repetitiveCheckbox->isChecked() != _model->data(_ui->alertsListView->currentIndex(), AlertModel::RepetitiveRole).toBool();
	updateButtonAvailability();
}

void ManageDialog::updateButtonAvailability() {
	bool enabled = _labelChanged || _descriptionChanged || _repetitiveChanged;
	_ui->updateButton->setEnabled(enabled);
	_ui->resetButton->setEnabled(enabled);
}

void ManageDialog::removeAlert() {
	QItemSelectionModel *selection = _ui->alertsListView->selectionModel();

	QModelIndex index = selection->currentIndex();
	if (index.isValid())
		_model->removeRow(index.row());

	refreshDetails();
}

void ManageDialog::refreshDetails() {
	updateAlertDetails(_ui->alertsListView->currentIndex());
}
