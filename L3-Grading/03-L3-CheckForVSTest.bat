echo off
cls
rem ******************
rem First check to see if the MS executable vstest.console.exe can be found
rem   if not echo a message and exit
rem   if yes then echo 'Go on to next step'
rem ******************
IF NOT EXIST "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe" (
   echo This batch file needs to run: vstest.console.exe
   echo Use Windows File Explorer to find it on your machine
   echo Once you find it, note down its pathname
   echo Then edit this batch file by fixing the pathname to vstest.console.exe
   pause
) else (
   echo This step check out
   echo SUCCESFUL: Go on to next step
   pause
)


