cmake_minimum_required(VERSION 3.0.0)
project(HACKAR VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME}
    main.cpp
    ES582.cpp
    SearchForHw.cpp
    )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(BOA_INCLUDE_PATH "C:/Program Files/ETAS/BOA_V2/Include")
set(BOA_LIBRARY_PATH "C:/Program Files/ETAS/BOA_V2/Bin/x64/Lib")
include_directories(${BOA_INCLUDE_PATH})
link_directories(${BOA_LIBRARY_PATH})
target_link_libraries(${PROJECT_NAME} ${BOA_LIBRARY_PATH}/dll-ocdProxy.lib ${BOA_LIBRARY_PATH}/dll-csiBind.lib)