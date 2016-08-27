Function Name Mangling
======================

If you want to use both Mesa and another OpenGL library in the same
application at the same time you may find it useful to compile Mesa with
*name mangling*. This results in all the Mesa functions being prefixed
with **mgl** instead of **gl**.

To do this, recompile Mesa with the compiler flag -DUSE\_MGL\_NAMESPACE.
Add the flag to CFLAGS in the configuration file which you want to use.
For example:

::

    CFLAGS += -DUSE_MGL_NAMESPACE

.. raw:: html

   </div>