#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonSelectFile_clicked();

    void loadTransactions(QByteArray bytearrayHashKey);

    void on_lineEditAddSum_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    int decryptQByteArray(const QByteArray& encryptedBytes, QByteArray& decryptedBytes, unsigned char *key);
    QJsonArray transactionsArray;

    bool decryptJson(unsigned char *key, QString filename);

    QString fileName = "C:\\Users\\bruh\\Documents\\221_329_Akhmadov\\json\\transactions.json";
};
#endif // MAINWINDOW_H
