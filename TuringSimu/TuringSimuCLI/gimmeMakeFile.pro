TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../TuringSimuCommon/Common/Source/AbstractMachineUserinterface.cpp \
    ../TuringSimuCommon/Common/Source/BaseTransition.cpp \
    ../TuringSimuCommon/Common/Source/ErrorDisplayableUserinterface.cpp \
    ../TuringSimuCommon/Common/Source/MachineType.cpp \
    ../TuringSimuCommon/Common/Source/State.cpp \
    ../TuringSimuCommon/UI/Sources/Localization.cpp \
    ../TuringSimuCommon/UI/Sources/MachineExecutionController.cpp \
    ../TuringSimuCommon/UI/Sources/NonDeterministicTuringMachineUIExecutionData.cpp \
    ../TuringSimuCommon/UI/Sources/TuringMachineUIExecutionData.cpp \
    ../TuringSimuCommon/UI/Sources/UIExecutionDataFactory.cpp \
    ../TuringSimu/Business/Source/MachineFactory.cpp \
    ../TuringSimu/Business/Source/NonDeterministicTuringMachine.cpp \
    ../TuringSimu/Business/Source/TuringMachine.cpp \
    ../TuringSimu/Business/Source/TuringMachineTapeHeader.cpp \
    ../TuringSimu/Common/Source/Transition.cpp \
    ../TuringSimu/IO/Source/Directives.cpp \
    ../TuringSimu/IO/Source/DiskIO.cpp \
    ../TuringSimu/IO/Source/DiskOutput.cpp \
    ../TuringSimuCLI/Business/Sources/BaseConsoleController.cpp \
    ../TuringSimuCLI/Business/Sources/MachineExecutionControllerFactory.cpp \
    ../TuringSimuCLI/Business/Sources/TuringMachineConsoleOutputController.cpp \
    ../TuringSimuCLI/Business/Sources/TuringMachineLogfileOutputController.cpp \
    ../TuringSimuCLI/UI/Sources/Console.cpp \
    ../TuringSimuCLI/Main.cpp

HEADERS += \
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
    ../TuringSimu/IO/Header/Directives.hpp \
    ../TuringSimu/IO/Header/DiskIO.hpp \
    ../TuringSimu/IO/Header/DiskOutput.hpp \
    ../TuringSimuCLI/Business/Header/BaseConsoleController.hpp \
    ../TuringSimuCLI/Business/Header/TuringMachineConsoleOutputController.hpp \
    ../TuringSimuCLI/Business/Header/TuringMachineLogfileOutputController.hpp \
    ../TuringSimuCLI/UI/Header/Console.hpp
