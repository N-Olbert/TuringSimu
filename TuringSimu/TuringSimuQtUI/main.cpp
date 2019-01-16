#include <QApplication>
#include "TuringSimuQtUI.hpp"
#include "TuringSimuQtPresenter.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	auto view = std::make_unique<TuringSimuQtUI>();
    auto presenter = std::make_unique<TuringSimuQtPresenter>(view.get());
    Q_UNUSED(presenter);
    view->show();

    return a.exec();
}
