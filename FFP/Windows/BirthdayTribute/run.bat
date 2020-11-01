cls

cl.exe /c /EHsc RenderGroup.cpp Scene2.cpp Scene3.cpp Scene4.cpp Scene1.cpp

rc.exe RESOURCES.rc
link.exe RenderGroup.obj Scene2.obj Scene3.obj Scene4.obj Scene1.obj RESOURCES.res gdi32.lib user32.lib kernel32.lib /SUBSYSTEM:WINDOWS

RenderGroup.exe

del RenderGroup.obj Scene2.obj Scene3.obj Scene4.obj Scene1.obj RESOURCES.res log.txt
