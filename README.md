# clang-dllimport-export-error-demo
Demonstration of clang's weird handling of dllimport/dllexport linking on windows/msys2/mingw-w64

This is a simple project, with two DLLs, using the "standard" windows method of defining macros for
`__declspec(dllexport)` and `__declspec(dllimport)`. However, linking fails.

Can see build log under windows/msys2/mingw-w64/clang on appveyor here:
[appveyor build history](https://ci.appveyor.com/project/realazthat/clang-dllimport-export-error-demo/history)



Branch  | Status
---     | ---
master  | [![Build Status](https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true)](https://ci.appveyor.com/project/realazthat/clang-dllimport-export-error-demo)
