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
	/**
	 * @brief Fill the fields with the details of a specific alert
	 *
	 * @param index QModelIndex of the alert in the model
	 */
	void updateAlertDetails(const QModelIndex &index);

	/**
	 * @brief Sets the content of the fields back to their original value
	 */
	void reset();

	/**
	 * @brief Update the model data with the values filled in the fields
	 */
	void updateModel();

	/**
	 * @brief The text in the label text edit changed
	 */
	void onLabelChanged();

	/**
	 * @brief The text in the description text edit changed
	 */
	void onDescriptionChanged();

	/**
	 * @brief The state of the repetitive check box changed
	 */
	void onRepetitiveChanged();

private:
	Ui::ManageDialog *_ui;

	AlertModel *_model;

	void updateButtonAvailability();

	bool _labelChanged;
	bool _descriptionChanged;
	bool _repetitiveChanged;
};

#endif // MANAGEDIALOG_HPP
