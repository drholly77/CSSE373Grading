echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build E1P3D project
rem ******************
cls
echo starting check and copy
IF EXIST buildFailures.txt (
   rem delete record of previous build failures
   del buildFailures.txt
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   set earnZero=false
   echo ===============================
   Find "name" %%i\README.md

   rem ----------------------------------------------------------------
   rem Check that List6.hpp exists and the project E1P3D exists
   rem If any don't exist, then do not compile, student earns zero
   rem ----------------------------------------------------------------
   IF NOT EXIST %%i\components\include\list\List6.hpp (
      echo List6.hpp not found
      set earnZero=true
   ) 
   IF NOT EXIST %%i\E1P3D ( 
      echo E1P3D project not found
      set earnZero=true
   )

   rem ----------------------------------------------------------------
   rem Build project E1P3D 
   rem ----------------------------------------------------------------
   IF !earnZero!==false (
      echo Debug mode compiling
      cd %%i\E1P3D
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" E1P3D.sln /ProjectConfig "Debug|x64" /Project E1P3D  /Build "Debug|x64" /Out E1P3D-BuildOutput.txt
      cd ..\..
   )

   rem ----------------------------------------------------------------
   rem Check to see that the 2 projects E1P3D and L4R built and generated a .dll
   rem ----------------------------------------------------------------
   IF NOT EXIST "%%i\E1P3D\x64\Debug\E1P3D.dll" (
      set earnZero=true
      echo FAILED build in Debug Mode

      echo %%i >> E1P3D-Grading\buildFailures.txt
      echo    FAILED build in Debug Mode >> E1P3D-Grading\buildFailures.txt
   ) 

  echo ===============================
  echo.
)
cd E1P3D-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
