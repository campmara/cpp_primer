@echo off

:: Create the build directory if it doesn't exist and enter it.
IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

set WARNINGS=-W4 -wd4189
set OPTIMIZATIONS=-EHsc -nologo

:: Compile x64.
call cl %WARNINGS% %OPTIMIZATIONS% ..\code\cpp_primer.cpp

:: Return to the previous directory.
popd
