# clang-dllimport-export-error-demo
Demonstration of clang's weird handling of dllimport/dllexport linking on windows/msys2/mingw-w64

This is a simple project, with two DLLs, using the "standard" windows method of defining macros for
`__declspec(dllexport)` and `__declspec(dllimport)`. However, linking fails.

Can see build log under windows/msys2/mingw-w64/clang on appveyor here:
[appveyor build history](https://ci.appveyor.com/project/realazthat/clang-dllimport-export-error-demo/history)



Branch  | Status
---     | ---
master  | [![Build Status](https://ci.appveyor.com/api/projects/status/kdp5x82x2iw3pxlp?svg=true)](https://ci.appveyor.com/project/realazthat/clang-dllimport-export-error-demo)


Build log output ([from here](https://ci.appveyor.com/project/realazthat/clang-dllimport-export-error-demo/build/1.0.2#L320), line 320):

```
[100%] Linking CXX shared library libmylib.dll
/C/msys64/mingw64/bin/cmake.exe -E remove -f CMakeFiles/mylib.dir/objects.a
/C/msys64/mingw64/bin/ar.exe cr CMakeFiles/mylib.dir/objects.a "CMakeFiles/mylib.dir/src/mylib.cpp.obj" 
/C/msys64/mingw64/bin/clang++.exe   -O3 -DNDEBUG  -shared -o libmylib.dll -Wl,--out-implib,libmylib.dll.a -Wl,--major-image-version,0,--minor-image-version,0 -Wl,--whole-archive CMakeFiles/mylib.dir/objects.a -Wl,--no-whole-archi
ve libbaselib.dll.a -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 
CMakeFiles/mylib.dir/objects.a(mylib.cpp.obj):(.text+0x87): undefined reference to `__imp__ZTI23InvalidRequestException'
 
CMakeFiles/mylib.dir/objects.a(mylib.cpp.obj):(.text[_ZN23InvalidRequestExceptionC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEES7_i]+0x97): undefined reference to `__imp__ZTV23InvalidRequestException'
 
clang++.exe
: error: linker command failed with exit code 1 (use -v to see invocation)
 
CMakeFiles/mylib.dir/build.make:97: recipe for target 'libmylib.dll' failed
make[2]: *** [libmylib.dll] Error 1
 
make[2]: Leaving directory '/c/projects/clang-dllimport-export-error-demo/build'
CMakeFiles/Makefile2:107: recipe for target 'CMakeFiles/mylib.dir/all' failed
make[1]: *** [CMakeFiles/mylib.dir/all] Error 2
 
make[1]: Leaving directory '/c/projects/clang-dllimport-export-error-demo/build'
Makefile:86: recipe for target 'all' failed
make: *** [all] Error 2
 
Command executed with exception: make: *** [all] Error 2
 
```


Try it yourself:

1. Install [msys2](https://msys2.github.io/)
2. Follow the instructions on the msys2 site
3. Run the commands in the `appveyor.yml` file under `install:` to install toolchain/compiler etc.
4. Install git: `pacman -S msys/git`
5. Build the project normally:

  ```
  cd ~
  git clone https://github.com/realazthat/clang-dllimport-export-error-demo.git
  cd clang-dllimport-export-error-demo
  mkdir build && cd build
  CXX=clang++ CC=clang++ cmake -G"MSYS Makefiles" .. -DCMAKE_VERBOSE_MAKEFILE=1 -DCMAKE_BUILD_TYPE="Release"
  ```


