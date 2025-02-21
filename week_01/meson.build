project('week_01', 'cpp',
       default_options: [
         'cpp_std=c++20',
         'warning_level=2',
         #'werror=true',
         #'b_sanitize=address'
       ])

# add_project_arguments(
#   '-Wall', '-Wextra', '-Wpedantic', '-fsanitize=address', '-g', '-std=c++20',
#   language: 'cpp'
# )

gtest_dep = dependency('gtest')
gtest_main_dep = dependency('gtest_main')

executable('hello_world', '01_hello_world/hello_world.cpp')
executable('read_input', '02_read_input/read_input.cpp')
executable('add_input', '03_add_input/add.cpp')
executable('factorial',
           ['04_factorial/main.cpp',
            '04_factorial/factorial.hpp',
            '04_factorial/factorial.cpp'],
          dependencies : gtest_dep)
executable('factorial_test',
           ['04_factorial/tests.cpp',
            '04_factorial/factorial.hpp',
            '04_factorial/factorial.cpp'],
          dependencies : [gtest_dep, gtest_main_dep])
