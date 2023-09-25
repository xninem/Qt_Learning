#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

void Dialog::do_chkBoxUnderline(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plt = txtEdit->palette();
    if (radioBlack->isChecked())
    {
        plt.setColor(QPalette::Text, Qt::black);
    }
    if (radioBlue->isChecked())
    {
        plt.setColor(QPalette::Text, Qt::blue);
    }
    if (radioRed->isChecked())
    {
        plt.setColor(QPalette::Text, Qt::red);
    }
    txtEdit->setPalette(plt);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    chkBoxUnderline = new QCheckBox("Underline");
    chkBoxItalic    = new QCheckBox("Italic");
    chkBoxBold      = new QCheckBox("Bold");
    QHBoxLayout *HLay1 = new QHBoxLayout();
    HLay1->addWidget(chkBoxUnderline);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    radioBlack      = new QRadioButton("black");
    radioBlue       = new QRadioButton("Blue");
    radioRed        = new QRadioButton("Red");
    QHBoxLayout *HLay2 = new QHBoxLayout();
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioBlue);
    HLay2->addWidget(radioRed);

    txtEdit         = new QPlainTextEdit;
    txtEdit->setPlainText("Hello World!\nProject 01\nData: 20230925\nAuthor:XJM");
    QFont font = txtEdit->font();
    font.setPointSize(12);
    txtEdit->setFont(font);

    btnClear        = new QPushButton("Clear");
    btnConfirm      = new QPushButton("Confirm");
    btnClose        = new QPushButton("Close");
    QHBoxLayout *HLay3 = new QHBoxLayout();
    HLay3->addWidget(btnClear);
    HLay3->addStretch(1);
    HLay3->addWidget(btnConfirm);
    HLay3->addWidget(btnClose);

    QVBoxLayout *VLay1 = new QVBoxLayout();
    VLay1->addLayout(HLay1);
    VLay1->addLayout(HLay2);
    VLay1->addWidget(txtEdit);
    VLay1->addLayout(HLay3);

    setLayout(VLay1);
    setWindowTitle("XJMS");

    connect(chkBoxUnderline , SIGNAL(clicked(bool)), this, SLOT(do_chkBoxUnderline(bool)));
    connect(chkBoxItalic    , SIGNAL(clicked(bool)), this, SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold      , SIGNAL(clicked(bool)), this, SLOT(do_chkBoxBold(bool)));

    connect(radioBlack      , SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));
    connect(radioBlue       , SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));
    connect(radioRed        , SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));

    connect(btnClear        , SIGNAL(clicked()),     this, SLOT(clear()));
    connect(btnConfirm      , SIGNAL(clicked()),     this, SLOT(accept()));
    connect(btnClose        , SIGNAL(clicked()),     this, SLOT(close()));

}

Dialog::~Dialog()
{
}
