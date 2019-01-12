#ifndef TURINGSIMUQTPRESENTER_H
#define TURINGSIMUQTPRESENTER_H

#include <QObject>
#include <../../TuringSimuCommon/UI/Header/MachineExecutionController.hpp>
#include "AbstractTuringSimuQtForm.hpp"

using namespace ts_ui;
using namespace ts_common;
using namespace ts_ui_business;
class TuringSimuQtPresenter : public QObject
{
    Q_OBJECT

    public:
        explicit TuringSimuQtPresenter(AbstractTuringSimuQtForm* view, QObject *parent = nullptr);

    private:
        AbstractTuringSimuQtForm* view;
        std::unique_ptr<MachineExecutionController> model;

    private slots:
        void HandleReadInFileButtonClicked() const;
};
#endif // TURINGSIMUQTPRESENTER_H
