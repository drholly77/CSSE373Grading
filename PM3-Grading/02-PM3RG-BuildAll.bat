   	��h��G\                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    raph3.hpp  not found
      echo %%i >> PM3-Grading\buildFailures.txt
      echo    UnlabeledUndirectedGraph3.hpp not found >> PM3-Grading\buildFailures.txt
   ) 

   rem ----------------------------------------------------------------
   rem Build PM3RG project 
   rem ----------------------------------------------------------------

   echo Release mode compiling
   cd %%i\PM3RG 
   "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" PM3RG.sln /ProjectConfig "Release|x64" /Project PM3RG  /Build "Release|x64" /Out PM3RG-BuildOutput.txt
   cd ..\..


   rem ----------------------------------------------------------------
   rem Check to see PM3RG built and generated a .dll
   rem ----------------------------------------------------------------

   IF NOT EXIST "%%i\PM3RG\x64\Release\PM3RG.dll" (
      echo PM3RG FAILED build in Release Mode

      echo %%i >> PM3-Grading\buildFailures.txt
      echo    FAILED build in Release Mode >> PM3-Grading\buildFailures.txt
   ) 


  echo ===============================
  echo.
)
cd PM3-Grading
echo "Done with building' phase"
echo "Check file buildFailures.txt for list of projects that did not build"
pause
