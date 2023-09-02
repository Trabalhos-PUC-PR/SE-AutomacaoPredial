cmake_minimum_required(VERSION 3.26)
project(20230902)

set(CMAKE_CXX_STANDARD 14)

# Tell cmake where Qt is located
set(Qt5_DIR "/usr/lib/cmake/Qt5/")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
# Required tells cmake to fail if it cannot fund the packages

# This enables the Meta Object Compiler (MOC)
set(CMAKE_AUTOMOC ON)

# To enable GUI design support, we need to perform two things
# 1st, enable user interface compiler (UIC)
set(CMAKE_AUTOUIC ON)

include_directories(firmware/common)
include_directories(firmware/x86_archLinux_qt_gui/AP)

add_executable(20230902
        firmware/common/behavior.c
        firmware/common/behavior.h
        firmware/common/hal.h
        firmware/common/sm.h
        firmware/common/sm1.c
        firmware/common/sm1.h
        firmware/x86_archLinux_qt_gui/AP/cedatank.cpp
        firmware/x86_archLinux_qt_gui/AP/cedatank.h
        firmware/x86_archLinux_qt_gui/AP/hal.c
        firmware/x86_archLinux_qt_gui/AP/led.h
        firmware/x86_archLinux_qt_gui/AP/main.cpp
        firmware/x86_archLinux_qt_gui/AP/mainwindow.cpp
        firmware/x86_archLinux_qt_gui/AP/mainwindow.h
        firmware/x86_archLinux_qt_gui/AP/threadbehavior.cpp
        firmware/x86_archLinux_qt_gui/AP/threadbehavior.h)

# Link the lib to the executable
target_link_libraries(20230902 Qt5::Core Qt5::Widgets)