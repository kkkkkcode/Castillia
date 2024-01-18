# 版本设置  
cmake_minimum_required(VERSION 3.14)  
# 声明项目名称与语言

cmake_policy(SET CMP0074 NEW)

project(demo LANGUAGES CXX)  
# 构建hello 

set(CMAKE_CXX_STANDARD 23)

set(Armadillo_ROOT "E:/Microsoft/VSlibraries/armadillo_x64-windows-rel")

set(BOOST_ROOT "E:/Microsoft/VSlibraries/boost-1.84.0")



find_package(Armadillo REQUIRED)

#find_package(c-ares REQUIRED) 


find_package(Boost 1.84.0 REQUIRED)


include_directories("E:/Microsoft/VSlibraries/chartdir_cpp_win/ChartDirector/include")
link_directories("E:/Microsoft/VSlibraries/chartdir_cpp_win/ChartDirector/lib64")




if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    set(Boost_LIBRARIES "E:/Microsoft/VSlibraries/boost-1.84.0/stage/lib")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()


include_directories(
${ARMADILLO_INCLUDE_DIRS}
#${c-ares_INCLUDE_DIR}
)
link_directories(${ARMADILLO_LIBRARY_DIRS})
link_libraries(
${ARMADILLO_LIBRARIES}
E:/Microsoft/VSlibraries/libxl-win-4.2.0/libxl-4.2.0/lib64/libxl.lib
#${c-ares_LIBRARY}
E:/Microsoft/VSlibraries/lapack-reference_x64-windows-rel/lib/lapack.lib
E:/Microsoft/VSlibraries/openblas_x64-windows-rel/lib/openblas.lib
)

include_directories(E:/Microsoft/VSlibraries/mlpack_x64-windows-rel/include
E:/Microsoft/VSlibraries/mlpack_x64-windows-rel/include/core
E:/Microsoft/VSlibraries/mlpack_x64-windows-rel/include/methods
E:/Microsoft/VSlibraries/ensmallen_x64-windows-rel/include
E:/Microsoft/VSlibraries/cereal_x64-windows-rel/include
E:/Microsoft/VSlibraries/libxl-win-4.2.0/libxl-4.2.0/include_cpp
)


include_directories(E:/Microsoft/VSlibraries/boost-1.84.0)
include_directories("E:/Microsoft/VSlibraries/openGA-master/openGA-master/src")
include_directories("E:/Microsoft/VSlibraries/eigen")
# 将源代码添加到此项目的可执行文件。
add_executable (CMakeProject2 "CMakeProject2.cpp" "CMakeProject2.h" "StrLearning.cpp" "DataAndC.cpp" "PtrLearning.c"   "GAdemo.h" "GAdemo.cpp")

target_link_libraries(CMakeProject2 ${Boost_LIBRARIES} chartdir70)

# TODO: 如有需要，请添加测试并安装目标。
