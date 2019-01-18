#-------------------------------------------------
#
# Project created by QtCreator 2019-01-17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TuringSimuQtUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        main.cpp \
        TuringSimuQtUI.cpp \
        TapeLetter.cpp \
        TuringMachineQtOutputController.cpp \
        TuringSimuQtPresenter.cpp \
        ../TuringSimu/Business/Source/MachineFactory.cpp \
        ../TuringSimu/Business/Source/NonDeterministicTuringMachine.cpp \
        ../TuringSimu/Business/Source/TuringMachine.cpp \
        ../TuringSimu/Business/Source/TuringMachineTapeHeader.cpp \
        ../TuringSimu/Common/Source/Transition.cpp \
        ../TuringSimu/IO/Source/Directives.cpp \
        ../TuringSimu/IO/Source/DiskIO.cpp \
        ../TuringSimu/IO/Source/DiskOutput.cpp \
        ../TuringSimuCommon/Common/Source/AbstractMachineUserinterface.cpp \
        ../TuringSimuCommon/Common/Source/BaseTransition.cpp \
        ../TuringSimuCommon/Common/Source/ErrorDisplayableUserinterface.cpp \
        ../TuringSimuCommon/Common/Source/MachineType.cpp \
        ../TuringSimuCommon/Common/Source/State.cpp \
        ../TuringSimuCommon/UI/Sources/Localization.cpp \
        ../TuringSimuCommon/UI/Sources/MachineExecutionController.cpp \
        ../TuringSimuCommon/UI/Sources/NonDeterministicTuringMachineUIExecutionData.cpp \
        ../TuringSimuCommon/UI/Sources/TuringMachineUIExecutionData.cpp \
        ../TuringSimuCommon/UI/Sources/UIExecutionDataFactory.cpp

HEADERS += \
        TuringSimuQtUI.hpp \
        AbstractTuringSimuQtForm.hpp \
        TapeLetter.hpp \
        TuringMachineQtOutputController.hpp \
        TuringSimuQtPresenter.hpp \
        ../TuringSimu/Business/Header/MachineFactory.hpp \
        ../TuringSimu/Business/Header/NonDeterministicTuringMachine.hpp \
        ../TuringSimu/Business/Header/TuringMachine.hpp \
        ../TuringSimu/Business/Header/TuringMachineTapeHeader.hpp \
        ../TuringSimu/Common/Header/Transition.hpp \
        ../TuringSimu/Common/Header/TuringMachineDefinition.hpp \
        ../TuringSimu/IO/Header/Directives.hpp \
        ../TuringSimu/IO/Header/DiskIO.hpp \
        ../TuringSimu/IO/Header/DiskOutput.hpp \
        ../TuringSimuCommon/Common/Header/AbstractMachine.hpp \
        ../TuringSimuCommon/Common/Header/AbstractMachineUserinterface.hpp \
        ../TuringSimuCommon/Common/Header/BaseComparable.hpp \
        ../TuringSimuCommon/Common/Header/BaseMachineDefinition.hpp \
        ../TuringSimuCommon/Common/Header/BaseTransition.hpp \
        ../TuringSimuCommon/Common/Header/ComparableHelpers.hpp \
        ../TuringSimuCommon/Common/Header/DynamicType.hpp \
        ../TuringSimuCommon/Common/Header/ErrorDisplayableUserinterface.hpp \
        ../TuringSimuCommon/Common/Header/HashSet.hpp \
        ../TuringSimuCommon/Common/Header/HeadDirection.hpp \
        ../TuringSimuCommon/Common/Header/MachineType.hpp \
        ../TuringSimuCommon/Common/Header/State.hpp \
        ../TuringSimuCommon/Common/Header/StringRepresentable.hpp \
        ../TuringSimuCommon/Common/Header/Utility.hpp \
        ../TuringSimuCommon/UI/Header/Localization.hpp \
        ../TuringSimuCommon/UI/Header/MachineExecutionController.hpp \
        ../TuringSimuCommon/UI/Header/MachineExecutionControllerFactory.hpp \
        ../TuringSimuCommon/UI/Header/MachineUIExecutionData.hpp \
        ../TuringSimuCommon/UI/Header/NonDeterministicTuringMachineUIExecutionData.hpp \
        ../TuringSimuCommon/UI/Header/Result.hpp \
        ../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp \
        ../TuringSimuCommon/UI/Header/UIExecutionDataFactory.hpp \
        ../TuringSimu/Business/Header/MachineFactory.hpp \
        ../TuringSimu/Business/Header/NonDeterministicTuringMachine.hpp \
        ../TuringSimu/Business/Header/TuringMachine.hpp \
        ../TuringSimu/Business/Header/TuringMachineTapeHeader.hpp \
        ../TuringSimu/Common/Header/Transition.hpp \
        ../TuringSimu/Common/Header/TuringMachineDefinition.hpp \
        ../TuringSimu/IO/Header/Directives.hpp \
        ../TuringSimu/IO/Header/DiskIO.hpp \
        ../TuringSimu/IO/Header/DiskOutput.hpp \
        ../TuringSimuCommon/Common/Header/AbstractMachine.hpp \
        ../TuringSimuCommon/Common/Header/AbstractMachineUserinterface.hpp \
        ../TuringSimuCommon/Common/Header/BaseComparable.hpp \
        ../TuringSimuCommon/Common/Header/BaseMachineDefinition.hpp \
        ../TuringSimuCommon/Common/Header/BaseTransition.hpp \
        ../TuringSimuCommon/Common/Header/ComparableHelpers.hpp \
        ../TuringSimuCommon/Common/Header/DynamicType.hpp \
        ../TuringSimuCommon/Common/Header/ErrorDisplayableUserinterface.hpp \
        ../TuringSimuCommon/Common/Header/HashSet.hpp \
        ../TuringSimuCommon/Common/Header/HeadDirection.hpp \
        ../TuringSimuCommon/Common/Header/MachineType.hpp \
        ../TuringSimuCommon/Common/Header/State.hpp \
        ../TuringSimuCommon/Common/Header/StringRepresentable.hpp \
        ../TuringSimuCommon/Common/Header/Utility.hpp \
        ../TuringSimuCommon/UI/Header/Localization.hpp \
        ../TuringSimuCommon/UI/Header/MachineExecutionController.hpp \
        ../TuringSimuCommon/UI/Header/MachineExecutionControllerFactory.hpp \
        ../TuringSimuCommon/UI/Header/MachineUIExecutionData.hpp \
        ../TuringSimuCommon/UI/Header/NonDeterministicTuringMachineUIExecutionData.hpp \
        ../TuringSimuCommon/UI/Header/Result.hpp \
        ../TuringSimuCommon/UI/Header/TuringMachineUIExecutionData.hpp \
        ../TuringSimuCommon/UI/Header/UIExecutionDataFactory.hpp

FORMS += \
        TuringSimuQtUI.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
