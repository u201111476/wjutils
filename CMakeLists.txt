cmake_minimum_required(VERSION 3.5) #设置cmake最低版本

set(target wjutils)        #设置target变量
project(${target})            #使用target变量作为工程名

add_subdirectory(src)       #加入子目录
