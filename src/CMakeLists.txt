add_executable(Tanks)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp *.h)
target_sources(Tanks PRIVATE ${SOURCE_FILES})
target_link_libraries(Tanks sfml-system sfml-window sfml-graphics sfml-audio Boost::system)
