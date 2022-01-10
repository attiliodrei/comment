@echo off
pushd "%~dp0"
setlocal enableextensions
ffmpeg.exe  -hide_banner -loglevel info -f dshow  -list_devices true -i ""  2>&1 | find "Mic" > %temp%\mic.txt
setlocal EnableDelayedExpansion
for /f "tokens=* usebackq" %%a in (%temp%\mic.txt) do (
    set z=%%a
    set z=!z:"=_!
    for /f "tokens=1-2 delims=_" %%a in ("!z!") do echo %%b
    for /f "tokens=* delims= " %%a in ('echo %%b') do set %%b=%%a

)