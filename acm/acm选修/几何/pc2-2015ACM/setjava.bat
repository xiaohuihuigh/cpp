@echo off
rem Purpose: This sets the PATH and CLASSPATH to run the system where
rem java is under E:\pc-20110417\jdk1.6.0_22
rem Author: pc2@ecs.csus.edu
rem Mon Apr 15 09:58:25 PDT 2002

set PC2=E:\pc-20120708
set JAVA=E:\pc-20120708\jdk1.6.0_22

rem might need to set systemroot on win95/98/ME
rem set SYSTEMROOT=c:\windows

set CLASSPATH=%PC2%;%JAVA%\lib;.;%CLASSPATH%
set PATH=%JAVA%\bin;%SYSTEMROOT%;%SYSTEMROOT%\system32;%PATH%

rem eof setjava.bat
