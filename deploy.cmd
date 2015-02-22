rmdir deploy /S /Q
mkdir deploy/
robocopy "diff-pdf" "deploy\diff-pdf"
copy "release\diff-pdf_GUI.exe" "deploy\diff-pdf\diff-pdf_GUI.exe"
windeployqt deploy/diff-pdf/diff-pdf_GUI.exe --no-translations