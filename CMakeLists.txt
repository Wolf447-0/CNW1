cmake_minimum_required(VERSION 3.16)
project(CNW LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(CNW
    main.cpp
    Sources/calendarmodel.h
    Sources/calendarmodel.cpp
)

target_include_directories(CNW PRIVATE ComponentsQml)
target_include_directories(CNW PRIVATE Sources)
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_add_qml_module(CNW
    URI QtFormQuick
    VERSION 1.0
    QML_FILES
        ComponentsQml/Main.qml
        ComponentsQml/ArrowR.qml
        ComponentsQml/ArrowL.qml
)

target_link_libraries(CNW
    PRIVATE Qt6::Quick
)
