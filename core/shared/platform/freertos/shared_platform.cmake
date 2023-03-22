set (PLATFORM_SHARED_DIR ${CMAKE_CURRENT_LIST_DIR})

add_definitions(-DBH_PLATFORM_FREERTOS)

include_directories(${PLATFORM_SHARED_DIR})
include_directories(${PLATFORM_SHARED_DIR}/../include)
include_directories(/home/xyj/work/bl_mcu_sdk/components/os/freertos/include)
include_directories(/home/xyj/work/bl_mcu_sdk/components/os/freertos/posix/include)
include_directories(/home/xyj/work/bl_mcu_sdk/examples/iwasm)
include_directories(/home/xyj/work/bl_mcu_sdk/components/os/freertos/portable/GCC/RISC-V/c906)


# include (${CMAKE_CURRENT_LIST_DIR}/../common/math/platform_api_math.cmake)

file (GLOB_RECURSE source_all ${PLATFORM_SHARED_DIR}/*.c)

set (PLATFORM_SHARED_SOURCE ${source_all} ${PLATFORM_COMMON_MATH_SOURCE})

# for deubg 2023年3月16日
message(AUTHOR_WARNING ${PLATFORM_SHARED_DIR} '----' ${SHARED_DIR} '---' ${PLATFORM_COMMON_MATH_SOURCE})
