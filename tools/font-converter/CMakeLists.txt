set(FontConverter_Sources
    FontConverter.cpp
)

add_executable(FontConverter ${FontConverter_Sources})
target_link_libraries(FontConverter LodenCore ${Loden_DEP_LIBS})
set_target_properties(FontConverter PROPERTIES FOLDER "tools")
