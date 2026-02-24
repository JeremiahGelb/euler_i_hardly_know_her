# Impl
set(euler_source_files
  euler1.cpp
  euler2.cpp
  euler3.cpp
  euler4.cpp
)
add_library(euler ${euler_source_files})
target_include_directories(euler PUBLIC .)