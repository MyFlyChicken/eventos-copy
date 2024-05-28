# This is converter generated file, and shall not be touched by user
#
# It is always re-generated if converter script is called multiple times
# Use CMakeLists.txt to apply user changes
cmake_minimum_required(VERSION 3.22)

# Sources
set(sources_SRCS ${sources_SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/3rd/unity/unity.c
    ${CMAKE_CURRENT_SOURCE_DIR}/eventos/eventos.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_fsm.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_port_test.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_reactor_led.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_test_etimer.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_test_event.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_test_fsm.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_test_heap.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_test_reactor.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/eos_test_sub.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/test/main.c    
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/posix/eos_led.c
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/posix/port_posix.c
    ${CMAKE_CURRENT_SOURCE_DIR}/examples/posix/main.c
)

message(${CMAKE_CURRENT_SOURCE_DIR})
# Include directories
set(include_c_DIRS ${include_c_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/3rd/unity
    ${CMAKE_CURRENT_SOURCE_DIR}/eventos
    ${CMAKE_CURRENT_SOURCE_DIR}/test
)
message(${include_c_DIRS})
set(include_cxx_DIRS ${include_cxx_DIRS}{{sr:include_cxx_DIRS}})
set(include_asm_DIRS ${include_asm_DIRS}{{sr:include_asm_DIRS}})

# Symbols definition
set(symbols_c_SYMB ${symbols_c_SYMB})
set(symbols_cxx_SYMB ${symbols_cxx_SYMB}{{sr:symbols_cxx_SYMB}})
set(symbols_asm_SYMB ${symbols_asm_SYMB}{{sr:symbols_asm_SYMB}})

# Compiler options
set(compiler_OPTS ${compiler_OPTS})

