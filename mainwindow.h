#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionZ_awijanie_wierszy_toggled(bool arg1);

    void on_actionOtw_rz_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionZapisz_triggered();

    void on_actionNowy_triggered();

    void on_actionZako_cz_triggered();

    void on_actionWytnij_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWklej_triggered();

    void on_action_Czcionka_triggered();

    void on_actionCofnij_triggered();

    void on_actionPrzywr_triggered();

    void on_actionO_programie_triggered();

private:
    Ui::MainWindow *ui;
    QString filename;
};

#endif // MAINWINDOW_H
