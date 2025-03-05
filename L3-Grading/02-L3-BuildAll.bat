echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build both L3D and L3R project
rem Build errors are recorded in the file "buildFailures.txt"
rem When this script terminates examine "buildFailures.txt" to see which builds failed
rem ******************
cls
echo starting build phase

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
   rem Check that List2.hpp exists and the 2 projects L3D and L3R exist
   rem If any don't exist, then do not compile, student earns zero
   rem ----------------------------------------------------------------
   IF NOT EXIST %%i\components\include\list\List2.hpp (
      set earnZero=true
   ) 
   IF NOT EXIST %%i\L3D ( 
      set earnZero=true
   )
   IF NOT EXIST %%i\L3R ( 
      set earnZero=true
   )

   rem ----------------------------------------------------------------
   rem Build the 2 projects L3D and L3R
   rem ----------------------------------------------------------------
   IF !earnZero!==false (
      echo Debug mode compiling
      cd %%i\L3D
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L3D.sln /ProjectConfig "Debug|x64" /Project L3D  /Build "Debug|x64" /Out L3D-BuildOutput.txt
      cd ..\..

      echo Release mode compiling
      cd %%i\L3R
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L3R.sln /ProjectConfig "Release|x64" /Project L3R  /Build "Release|x64" /Out L3R-BuildOutput.txt
      cd ..\..
   )

   rem ----------------------------------------------------------------
   rem Check to see that the 2 projects L3D and L3R built and generated a .dll
   rem ----------------------------------------------------------------
   IF NOT EXIST "%%i\L3D\x64\Debug\L3D.dll" (
      set earnZero=true
      echo FAILED build in Debug Mode
      echo %%i >> L3-Grading\buildFailures.txt
      echo    FAILED build in Debug Mode >> L3-Grading\buildFailures.txt
   ) 
   IF NOT EXIST "%%i\L3R\x64\Release\L3R.dll" (
      set earnZero=true
      echo FAILED build in Release Mode
      echo %%i >> L3-Grading\buildFailures.txt
      echo    FAILED build in Release Mode >> L3-Grading\buildFailures.txt
   ) 

  echo ===============================
  echo.
)
cd L3-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
