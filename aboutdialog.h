#ifndef ABOUTDIALOG
#define ABOUTDIALOG
#include <QDialog>
#include "ui_dialog.h"

class AboutDialog : public QDialog, public Ui::Dialog {
    Q_OBJECT

public:
    AboutDialog( QWidget * parent = 0);
};
#endif // ABOUTDIALOG

