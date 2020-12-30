#ifndef HARDWAREKEYSTOREDIALOG_H
#define HARDWAREKEYSTOREDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QString>

namespace Ui {
class HardwareKeystoreDialog;
}

class HardwareKeystoreDialogPriv;

/**
 * @brief The HardwareKeystoreDialog class Hardware keystore dialog
 */
class HardwareKeystoreDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief HardwareKeystoreDialog Constructor
     * @param devices List of devices
     * @param parent Parent widget
     */
    explicit HardwareKeystoreDialog(const QStringList& devices, QWidget *parent = 0);

    /**
     * @brief ~HardwareKeystoreDialog Destructor
     */
    ~HardwareKeystoreDialog();

    /**
     * @brief currentIndex Get the currently selected index
     * @return Current index
     */
    int currentIndex() const;

    /**
     * @brief setCurrentIndex Set the currently selected index
     * @param index Current index
     */
    void setCurrentIndex(int index);

    /**
     * @brief SelectDevice Select hardware keystore device
     * @param fingerprint Fingerprint of the selected device
     * @param errorMessage Error message during device selection
     * @param canceled Device selection canceled by the user
     * @param parent Parent widget
     * @return true: device selected; false: device not selected
     */
    static bool SelectDevice(QString& fingerprint, QString& errorMessage, bool& canceled, QWidget *parent = 0);
    static bool AskDevice(QString& fingerprint, QString& message, QWidget *parent = 0);

private Q_SLOTS:
    void on_cancelButton_clicked();
    void on_nextButton_clicked();

private:
    Ui::HardwareKeystoreDialog *ui;
    HardwareKeystoreDialogPriv *d;
};

#endif // HARDWAREKEYSTOREDIALOG_H
