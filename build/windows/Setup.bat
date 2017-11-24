set CUTEGEDCOM_DATA_DIR=%~dp0..\..\test\data

set QTDIR=D:\Qt\Qt5.9.1\5.9.1\msvc2015_64
set VSDIR=C:\Program Files (x86)\Microsoft Visual Studio 14.0
set QMAKESPEC=win32-msvc

call "%VSDIR%\VC\vcvarsall.bat" x64

%QTDIR%\bin\qmake.exe -tp vc -r ../../CuteGedcom.pro

set PATH=%PATH%;%QTDIR%\bin;%~dp0\src\debug

devenv CuteGedcom.sln