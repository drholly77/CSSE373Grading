echo off
SETLOCAL EnableDelayedExpansion
rem ***************************************
rem This Windows batch does its work in the student's repo
rem Preconditions: the GradeScripts folder and L1Sol.exe must exist 
rem                in the student's repo in the folder:
rem                csse373devenv202430-*\L1\x64\Release
rem                where '*' (above) is a wildcard representing the specific
rem                student's repo name
rem Run L1Sol.exe on each of the test scripts found
rem in GradeScripts\ folder, sending the output to the file solutionOutput.txt
rem storing it in the folder csse373devenv202430-*\L1\x64\Release\
rem ***************************************
IF EXIST FailureNoL1SolExeFound.txt (
   del FailureNoL1SolExeFound.txt 
)
cd ..
for /d %%i in (csse373devenv202430-*) do (
   IF EXIST "%%i\L1\x64\Release\L1Sol.exe" (
	cd %%i\L1\x64\Release
        echo Running Test Scripts > solutionOutput.txt
        for /r %%i in (GradeScripts\*.txt) do (
          echo run script: %%i
	  echo ### >> solutionOutput.txt
	  echo run script: %%i >> solutionOutput.txt
	  echo *** >> solutionOutput.txt
	  L1Sol.exe g < %%i >> solutionOutput.txt
        )
        cd ..\..\..\..
   ) else (
       echo %%i\L1Sol .exe non-existent >> L1-Grading\FailureNoL1SolExeFound.txt 
   )
)
cd L1-Grading
pause
 




