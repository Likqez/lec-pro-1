cmake_minimum_required(VERSION 3.27)
project(untitled C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled 02/line-interest.c
        03/euklid.c
        03/limits.c
        03/ascii.c
        03/multitable.c
        03/factorial.c
        03/resistance.c
        03/easter.c
        04/bigdivision.c
        04/multitable_array.c
        04/euklid_ptr.c
        04/multitable_array_ptr.c
        05/number_conversion.c
        05/to_the_power_of.c
        05/number_prompts.c
        05/string_manipulation.c
        06/random_num_game.c
        06/file_cards.c
        sorting.c)
