@echo off

echo ---- Setup script ----

set debug="bin\Debug\"
set release="bin\Release\"

mkdir %debug% > nul
mkdir %release% > nul

echo ^> steam_api.dll..

set steam_api_dll="sdk\SteamAPI\lib\steam_api.dll"
copy %steam_api_dll% %debug% > nul
copy %steam_api_dll% %release% > nul

echo ^> done

echo ^> steam_appid.txt..

set steam_appid_txt="data\steam_appid.txt"

copy %steam_appid_txt% %debug% > nul
copy %steam_appid_txt% %release% > nul

echo ^> done

echo ---- end ----
rem EOF
