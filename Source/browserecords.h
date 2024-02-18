#ifndef BROWSERECORDS_H
#define BROWSERECORDS_H

#include <QDialog>

namespace Ui {
class BrowseRecords;
}

class BrowseRecords : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseRecords(QWidget *parent = nullptr);
    ~BrowseRecords();

private:
    Ui::BrowseRecords *ui;
};

#endif // BROWSERECORDS_H
