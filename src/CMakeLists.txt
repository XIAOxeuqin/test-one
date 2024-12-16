SET(INCLUDE ${CMAKE_SOURCE_DIR}/include)

FILE(GLOB SOURCE "*.cpp")
LIST(REMOVE_ITEM SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)
LIST(REMOVE_ITEM SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

ADD_COMPILE_OPTIONS("-Wall")
ADD_COMPILE_OPTIONS("-Werror")
ADD_LIBRARY(training ${SOURCE}
        ExecutorImpl.cpp
        ../include/Executor.h
        ../include/ExecutorImpl.h
        ../include/PoseHandler.h
        PoseHandler.cpp
)

TARGET_INCLUDE_DIRECTORIES(training PUBLIC "${INCLUDE}")
