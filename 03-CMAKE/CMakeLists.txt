cmake_minimum_required(VERSION 3.10)
project (projeto_basico)


add_executable(vector_ops pj_pt3.cpp func.cpp) 
target_compile_options(vector_ops PUBLIC -O3)


add_executable(vector_ops2 pj_pt3.cpp func.cpp) 
target_compile_options(vector_ops2 PUBLIC -O2)


add_executable(vector_ops_no_opt pj_pt3.cpp func.cpp) 
target_compile_options(vector_ops PUBLIC -O0)


add_executable(vector_ops_simd pj_pt3.cpp func.cpp) 
target_compile_options(vector_ops_simd PUBLIC -O3 -ffast-math -mavx)
