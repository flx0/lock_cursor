CC = cl.exe
RM = del

lock_cursor.exe: lock_cursor.obj
	link lock_cursor.obj User32.lib Gdi32.lib /SUBSYSTEM:WINDOWS

lock_cursor.obj:
	$(CC) lock_cursor.c -c

clean:
	$(RM) lock_cursor.obj