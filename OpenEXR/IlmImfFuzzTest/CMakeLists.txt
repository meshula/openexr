# SPDX-License-Identifier: BSD-3-Clause
# Copyright Contributors to the OpenEXR Project.

add_executable( IlmImfFuzzTest
  fuzzFile.cpp
  main.cpp
  testFuzzDeepTiles.cpp
  testFuzzDeepScanLines.cpp
  testFuzzScanLines.cpp
  testFuzzTiles.cpp
)
target_link_libraries(IlmImfFuzzTest OpenEXR::IlmImf)
set_target_properties(IlmImfFuzzTest PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
option(OPENEXR_RUN_FUZZ_TESTS  "Controls whether to include the fuzz tests (slow) in default test cases, there is a custom fuzz target" OFF)
if(OPENEXR_RUN_FUZZ_TESTS)
  add_test(NAME OpenEXR.ImfFuzz COMMAND $<TARGET_FILE:IlmImfFuzzTest>)
  set_tests_properties(OpenEXR.ImfFuzz PROPERTIES TIMEOUT 36000)
endif()

add_custom_target(fuzz ${CMAKE_CURRENT_BINARY_DIR}/IlmImfFuzzTest)
add_dependencies(fuzz IlmImfFuzzTest)
