cmake_minimum_required(VERSION 3.16)
project(SimpleP VERSION 1.0.0)

include_directories(headers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*,-modernize-use-trailing-return-type,-modernize-use-nodiscard,readability-*,-readability-braces-around-statements,-readability-magic-numbers,-readability-else-after-return,-clang-analyzer-optin.*")

find_package(Qt5 COMPONENTS Widgets Core Gui)

set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons.qrc)

qt5_add_resources(RES_SOURCES ${RESOURCES})

set(SOURCES src/main.cpp src/mainwindow.cpp src/brush.cpp src/bucket.cpp src/colorpicker.cpp src/ellipse.cpp src/eraser.cpp src/image.cpp src/line.cpp src/pencil.cpp src/rect.cpp src/tool.cpp src/triangle.cpp)

set(HEADERS headers/mainwindow.h headers/brush.h headers/bucket.h headers/colorpicker.h headers/ellipse.h headers/eraser.h headers/image.h headers/line.h headers/pencil.h headers/rect.h headers/tool.h headers/triangle.h)

set(UI forms/mainwindow.ui)

qt5_wrap_ui(UI_HEADERS ${UI})

add_executable(SimpleP ${SOURCES} ${HEADERS} ${UI_HEADERS} ${RES_SOURCES})
qt5_use_modules(SimpleP Widgets Core Gui)

target_link_libraries(SimpleP Qt5::Widgets Qt5::Core Qt5::Gui)
