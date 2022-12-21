
cd .

chcp 1252

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2022b\bin\win64\gmake"  DEPRULES=1 -j9  -f RLC_embedded_coder.mk all) else ("C:\PROGRA~1\MATLAB\R2022b\bin\win64\gmake"  DEPRULES=1 -j9  -f RLC_embedded_coder.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1