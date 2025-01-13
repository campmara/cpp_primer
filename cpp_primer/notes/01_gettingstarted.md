# Getting Started

How does my system handle an exit code of `-1` from a `main()` function?
> C:\work\cpp\learning\cpp_primer\bin\Debug-x64\cpp_primer\cpp_primer.exe (process 31800) exited with code -1 (0xffffffff).

`cerr` and `clog` are also part of the `<iostream>` library.

`cerr` is the *standard error* and `clog` is for general logging during execution.

Your print statements in a C++ program should always flush the stream if you are using `ostream`.

```c++
std::cin >> v1 >> v2;
// is equivalent to
(std::cin >> v1) >> v2;
// is also equivalent to
std::cin >> v1;
std::cin >> v2;
```