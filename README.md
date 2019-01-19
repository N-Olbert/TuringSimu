# TuringSimu
A turing simulator created as part of the cpp course at the DHBW Stuttgart Campus Horb

# Building

##### A note for Linux
The makefiles we provide were proven to work on a machine running Ubuntu 18.10 with latest gcc + build-essential installed. 
Working Qt versions were 4.8 and 5.12.
##### A note for Visual Studio
When checking out this repository it is possible that the starting project is TuringSimu. Since that project ultimately compiles into a static library VS cannot start it. Thus it is necessary to change the starting project to TuringSimuCLI by right-clicking on it and setting it as such.

## TuringSimuTests
NOTE: This part is only required if you want to use Visual Studio. On Linux you may simply install boost and use the provided makefile.

To build the "TuringSimuTests"-project the following enviornment variables must be set:

* #### BOOST_ROOT_DIR
        The directory which contains the Boost.org (header) files, for example *C:\boost\boost_1_67_0*
* #### BOOST_LIB_DIR
        The directory which contains the Boost.org binarys, for example *C:\boost\boost_1_67_0\stage\lib*

## TuringsSimuQtUi
To build the "TuringSimuQtUI"-project choose one of the following methods:

* #### Qt Creator (recommended)
        Open the *TuringSimuQtUi.pro*-file located at *..\TuringSimu\TuringSimuQtUI* and build using Qt Creator
* #### Visual Studio + Qt Visual Studio Tools (a bit tricky)
        Install the *Qt Visual Studio Tools*. Open the solution within Visual Studio. 
        Rightclick the "TuringSImuQtUI"-project and choose "Qt project settings". 
        In the upcomming dialog select the version of Qt you would like to use (default name:"msvc2017")
        within the "Propeties"-tab and make sure that you check the following modules within the "Qt Modules"-tab:
        - Core
        - GUI
        - Widgets
 One small benefit of using the more complex Visual Studio approach is the fact that libarys are used (whereas the .pro-approach compiles everything into one large exe).

## TuringSimuCLI
To build this project either use Visual Studio 17 and build the corresponding project or use the makefile on any linux based system.
