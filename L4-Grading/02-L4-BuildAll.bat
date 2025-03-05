echo off
SETLOCAL EnableDelayedExpansion
rem ******************
rem Build both L4D and L4R project
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
   rem Check that List3.hpp exists and the 2 projects L4D and L4R exist
   rem If any don't exist, then do not compile, student earns zero
   rem ----------------------------------------------------------------
   IF NOT EXIST %%i\components\include\list\List3.hpp (
      set earnZero=true
   ) 
   IF NOT EXIST %%i\L4D ( 
      set earnZero=true
   )
   IF NOT EXIST %%i\L4R ( 
      set earnZero=true
   )

   rem ----------------------------------------------------------------
   rem Build the 2 projects L4D and L4R
   rem ----------------------------------------------------------------
   IF !earnZero!==false (
      echo Debug mode compiling
      cd %%i\L4D
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L4D.sln /ProjectConfig "Debug|x64" /Project L4D  /Build "Debug|x64" /Out L4D-BuildOutput.txt
      cd ..\..

      echo Release mode compiling
      cd %%i\L4R
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L4R.sln /ProjectConfig "Release|x64" /Project L4R  /Build "Release|x64" /Out L4R-BuildOutput.txt
      cd ..\..
   )

   rem ----------------------------------------------------------------
   rem Check to see that the 2 projects L4D and L4R built and generated a .dll
   rem ----------------------------------------------------------------
   IF NOT EXIST "%%i\L4D\x64\Debug\L4D.dll" (
      set earnZero=true
      echo FAILED build in Debug Mode

      echo %%i >> L4-Grading\buildFailures.txt
      echo    FAILED build in Debug Mode >> L4-Grading\buildFailures.txt
   ) 
   IF NOT EXIST "%%i\L4R\x64\Release\L4R.dll" (
      set earnZero=true
      echo FAILED build in Release Mode

      echo %%i >> L4-Grading\buildFailures.txt
      echo    FAILED build in Release Mode >> L4-Grading\buildFailures.txt
   ) 


  echo ===============================
  echo.
)
cd L4-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
