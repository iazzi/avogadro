# Project name
# project(EspressoExtension)

# Minimum version of CMake that can be used
# cmake_minimum_required(VERSION 2.6)

# set(QT_MIN_VERSION "4.5.0")
# find_package(Qt4 COMPONENTS QtCore QtGui QtXml REQUIRED)
# find_package(Avogadro REQUIRED)
# find_package(OpenBabel2 REQUIRED)
# include(${Avogadro_USE_FILE})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${QT_INCLUDE_DIR})

# include_directories(${OpenBabel2_INCLUDE_DIRS})

set( espressoextension_SRCS
        espressoextension.cpp
        espressopwscfconfig.cpp
        espressopwscfdialog.cpp
)

avogadro_plugin_nogl(qespresso
                 "${espressoextension_SRCS}")

target_link_libraries(qespresso ${QT_QTXML_LIBRARIES})
