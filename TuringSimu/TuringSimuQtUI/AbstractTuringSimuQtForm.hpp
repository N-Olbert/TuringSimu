#ifndef ABSTRACTTURINGSIMUQTUI_H
#define ABSTRACTTURINGSIMUQTUI_H
#include <string>
class AbstractTuringSimuQtForm
{
    //Methods
    public:
        virtual std::string GetPathTextBoxInput() = 0;

    //Signals
    public:
        virtual ~AbstractTuringSimuQtForm() = default;
        virtual void ReadInFileButtonClicked() = 0;
};

#endif // ABSTRACTTURINGSIMUQTUI_H
