#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QCheckBox;
class QRadioButton;
class QPlainTextEdit;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT

private:
    QCheckBox *chkBoxUnderline;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    QRadioButton *radioBlack;
    QRadioButton *radioBlue;
    QRadioButton *radioRed;

    QPlainTextEdit *txtEdit;
    QPushButton *btnClear;
    QPushButton *btnConfirm;
    QPushButton *btnClose;

private slots:
    void do_chkBoxUnderline (bool checked);
    void do_chkBoxItalic    (bool checked);
    void do_chkBoxBold      (bool checked);

    void do_setFontColor    ();


public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
