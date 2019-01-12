#include <QApplication>
#include "TuringSimuQtUI.hpp"
#include "TuringSimuQtPresenter.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TuringSimuQtUI* w = new TuringSimuQtUI{};
    TuringSimuQtPresenter *presenter = new TuringSimuQtPresenter(w);
    Q_UNUSED(presenter);
    w->show();

    return a.exec();
}
