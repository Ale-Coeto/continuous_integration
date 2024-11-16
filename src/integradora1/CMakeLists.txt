set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/FileReader.h")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/Kmp.h")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/Lcs.h")
set(LIBRARY_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/Palindrome.h")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library("LibIntegradora1" STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories("LibIntegradora1" PUBLIC ${LIBRARY_INCLUDES})
target_include_directories(LibIntegradora1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
    "LibIntegradora1"
    PRIVATE nlohmann_json::nlohmann_json
            fmt::fmt
            spdlog::spdlog
            cxxopts::cxxopts)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "LibIntegradora1"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        "LibIntegradora1"
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("LibIntegradora1")
endif()