cmake_minimum_required(VERSION 3.5)

project(CodeBlocPP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES CodeBlocPP_en_US.ts)

set(PROJECT_SOURCES
        main.cpp
        mainview.cpp
        mainview.h
        mainview.ui
        backend/compiler.h
        backend/compiler.cpp
        backend/variable.h
        backend/variable.cpp
        backend/command.h
        backend/commands/operationcommand.cpp
        backend/commands/operationcommand.h
        backend/commands/writecommand.cpp
        backend/commands/writecommand.h
        backend/commands/jumpcommand.cpp
        backend/commands/jumpcommand.h
        backend/commands/ifcommand.cpp
        backend/commands/ifcommand.h
        frontend/commandview.h
        frontend/commandview.cpp
        frontend/dynamicvariable.h
        frontend/dynamicvariable.cpp
        frontend/outputview.h
        frontend/outputview.cpp
        ${TS_FILES}
        )

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CodeBlocPP
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET CodeBlocPP APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else ()
    if (ANDROID)
        add_library(CodeBlocPP SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else ()
        add_executable(CodeBlocPP
                ${PROJECT_SOURCES}
                )
    endif ()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif ()

target_link_libraries(CodeBlocPP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(CodeBlocPP PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CodeBlocPP)
endif ()
