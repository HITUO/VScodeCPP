@REM  .\ZZZ.clean_exe.bat

@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

REM 切换到批处理文件所在目录（确保路径正确）
cd /d "%~dp0"

echo ========================================
echo     可执行文件清理工具
echo ========================================
echo.
echo 当前工作目录: %cd%
echo.

REM 统计将要删除的文件数量
set count=0
for /r %%i in (*.exe) do (
    set /a count+=1
)

if !count!==0 (
    echo 📂 当前文件夹中没有找到 .exe 文件
    echo.
    pause
    exit /b
)

echo ⚠️  警告：将删除 !count! 个 .exe 文件！
echo.
echo 按 Ctrl+C 取消，或按任意键继续...
pause >nul
echo.

REM 显示并删除文件
echo 正在删除以下文件：
echo --------------------------------
for /r %%i in (*.exe) do (
    echo   [删除] %%i
    del "%%i" 2>nul
)
echo --------------------------------
echo.

echo ✅ 成功删除 !count! 个文件！
echo.
pause