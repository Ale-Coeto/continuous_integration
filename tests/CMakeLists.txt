include(Catch)

add_executable("UnitTestFoo" "test_foo.cc")
target_link_libraries("UnitTestFoo" PUBLIC "LibFoo")
target_link_libraries("UnitTestFoo" PRIVATE Catch2::Catch2WithMain)

add_executable("UnitTestBar" "test_bar.cc")
target_link_libraries("UnitTestBar" PUBLIC "LibBar")
target_link_libraries("UnitTestBar" PRIVATE Catch2::Catch2WithMain)

add_executable("UnitTestIntegradora1" "test_integradora1.cpp")
target_link_libraries("UnitTestIntegradora1" PUBLIC "LibIntegradora1")
target_link_libraries("UnitTestIntegradora1" PRIVATE Catch2::Catch2WithMain)
# target_link_libraries(UnitTestIntegradora1
#     PUBLIC LibIntegradora1
#            Catch2::Catch2WithMain
# )

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "UnitTestFoo"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
    target_set_warnings(
        TARGET
        "UnitTestBar"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
    target_set_warnings(
        TARGET
        "UnitTestIntegradora1"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

catch_discover_tests("UnitTestFoo")
catch_discover_tests("UnitTestBar")
catch_discover_tests("UnitTestIntegradora1")

if(ENABLE_COVERAGE)
    set(COVERAGE_MAIN "coverage")
    set(COVERAGE_EXCLUDES
        "${PROJECT_SOURCE_DIR}/app/*"
        "${PROJECT_SOURCE_DIR}/cmake/*"
        "${PROJECT_SOURCE_DIR}/docs/*"
        "${PROJECT_SOURCE_DIR}/external/*"
        "${PROJECT_SOURCE_DIR}/tests/*"
        "${PROJECT_SOURCE_DIR}/build/*"
        "/usr/include/*")
    set(COVERAGE_EXTRA_FLAGS)
    # set(COVERAGE_DEPENDENCIES "UnitTestFoo" "UnitTestBar")
    set(COVERAGE_DEPENDENCIES "UnitTestFoo" "UnitTestBar" "UnitTestIntegradora1")

    setup_target_for_coverage_gcovr_html(
        NAME
        ${COVERAGE_MAIN}
        EXECUTABLE
        ctest
        DEPENDENCIES
        ${COVERAGE_DEPENDENCIES}
        BASE_DIRECTORY
        ${CMAKE_SOURCE_DIR})
endif()
