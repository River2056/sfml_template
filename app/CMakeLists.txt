set(EXECUTABLE_SOURCES 
    "main.cpp")

add_executable(${PROJECT_NAME} ${EXECUTABLE_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml-system
    sfml-window
    sfml-network
    sfml-graphics
    sfml-audio
    sfml-main)

if (WIN32 AND BUILD_SHARED_LIBS)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
endif()
