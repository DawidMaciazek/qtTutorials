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

    void openFile();
    void saveFile();

    void changeText();

    ~MainWindow();

private slots:
    //void onButtonClicked();
    void on_actionOpen_triggered();


    //void onActionSaveTiggered();
    //void onActionSaveAsTiggered();

    //void onActionCloseTiggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
