Debugging Tips
==============

Normally Mesa (and OpenGL) records but does not notify the user of
errors. It is up to the application to call ``glGetError`` to check for
errors. Mesa supports an environment variable, MESA\_DEBUG, to help with
debugging. If MESA\_DEBUG is defined, a message will be printed to
stdout whenever an error occurs.

More extensive error checking is done when Mesa is compiled with the
DEBUG symbol defined. You'll have to edit the Make-config file and add
-DDEBUG to the CFLAGS line for your system configuration. You may also
want to replace any optimization flags with the -g flag so you can use
your debugger. After you've edited Make-config type 'make clean' before
recompiling.

In your debugger you can set a breakpoint in \_mesa\_error() to trap
Mesa errors.

There is a display list printing/debugging facility. See the end of
src/dlist.c for details.

.. raw:: html

   </div>