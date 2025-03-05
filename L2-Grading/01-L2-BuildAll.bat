echo off
rem ******************
rem Builds L2.dll for each repo in Debug mode
rem ******************
cls
cd ..
for /d %%i in (csse373devenv202430-*) do (
   echo Building L2 in repo: %%i
   Find "name" %%i\README.md
IF EXIST %%i\L2 (   
      cd %%i\L2
      echo Debug mode compiling
      "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" L2.sln /ProjectConfig "Debug|x64" /Project L2  /Build "Debug|x64" /Out buildOutputDebug.txt
      IF NOT EXIST x64\Debug\L2.dll (
          echo L2 failed to build in Debug mode
      )
      cd ..\..
) ELSE (
   echo %%i does not have L2 folder
)
echo ===============================
echo.
)
cd L2-Grading
echo "Done"
pause
