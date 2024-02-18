#include "browserecords.h"
#include "ui_browserecords.h"

BrowseRecords::BrowseRecords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseRecords)
{
    ui->setupUi(this);
}

BrowseRecords::~BrowseRecords()
{
    delete ui;
}
