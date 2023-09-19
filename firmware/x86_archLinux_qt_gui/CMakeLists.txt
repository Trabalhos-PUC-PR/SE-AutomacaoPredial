cmake_minimum_required(VERSION 3.26)
project(20230902_x86_archLinux_qt_gui)

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

include_directories(../common)
include_directories(AP)

add_executable(20230902_x86_archLinux_qt_gui
        ../common/behavior.c
        ../common/behavior.h
        ../common/hal.h
        ../common/sm.h
        ../common/sm1.c
        ../common/sm1.h
        AP/cedatank.cpp
        AP/cedatank.h
        AP/hal.c
        AP/led.h
        AP/main.cpp
        AP/mainwindow.cpp
        AP/mainwindow.h
        AP/threadbehavior.cpp
        AP/threadbehavior.h
        ../common/sm2.c
        ../common/sm2.h
        ../common/sm3.c
        ../common/sm3.h)

# Link the lib to the executable
target_link_libraries(20230902_x86_archLinux_qt_gui Qt5::Core Qt5::Widgets)