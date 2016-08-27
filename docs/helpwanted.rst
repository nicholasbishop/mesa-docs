Help Wanted / To-Do List
========================

We can always use more help with the Mesa project. Here are some
specific ideas and areas where help would be appreciated:

#. **Driver patching and testing.** Patches are often posted to the
   `mesa-dev mailing
   list <http://lists.freedesktop.org/mailman/listinfo/mesa-dev>`__, but
   aren't immediately checked into git because not enough people are
   testing them. Just applying patches, testing and reporting back is
   helpful.
#. **Driver debugging.** There are plenty of open bugs in the `bug
   database <https://bugs.freedesktop.org/describecomponents.cgi?product=Mesa>`__.
#. **Remove aliasing warnings.** Enable gcc -Wstrict-aliasing=2
   -fstrict-aliasing and track down aliasing issues in the code.
#. **Windows driver building, testing and maintenance.** Fixing MSVC
   builds.
#. **Contribute more tests to
   `Piglit <http://piglit.freedesktop.org/>`__.**
#. **Automatic testing.** It would be great if someone would set up an
   automated system for grabbing the latest Mesa code and run tests
   (such as piglit) then report issues to the mailing list.

You can find some further To-do lists here:

**Common To-Do lists:**

-  `**GL3.txt** <http://cgit.freedesktop.org/mesa/mesa/tree/docs/GL3.txt>`__
   - Status of OpenGL 3.x / 4.x features in Mesa.
-  `**MissingFunctionality** <http://dri.freedesktop.org/wiki/MissingFunctionality>`__
   - Detailed information about missing OpenGL features.

**Driver specific To-Do lists:**

-  `**LLVMpipe** <http://cgit.freedesktop.org/mesa/mesa/tree/src/gallium/docs/llvm-todo.txt>`__
   - Software driver using LLVM for runtime code generation.
-  `**radeonsi** <http://dri.freedesktop.org/wiki/RadeonsiToDo>`__ -
   Driver for AMD Southern Island.
-  `**r600g** <http://dri.freedesktop.org/wiki/R600ToDo>`__ - Driver for
   ATI/AMD R600 - Northern Island.
-  `**r300g** <http://dri.freedesktop.org/wiki/R300ToDo>`__ - Driver for
   ATI R300 - R500.
-  `**i915g** <http://cgit.freedesktop.org/mesa/mesa/tree/src/gallium/drivers/i915/TODO>`__
   - Driver for Intel i915/i945.

If you want to do something new in Mesa, first join the Mesa developer's
mailing list. Then post a message to propose what you want to do, just
to make sure there's no issues.

Anyone is welcome to contribute code to the Mesa project. By doing so,
it's assumed that you agree to the code's licensing terms.

Finally:

#. Try to write high-quality code that follows the existing style.
#. Use uniform indentation, write comments, use meaningful identifiers,
   etc.
#. Test your code thoroughly. Include test programs if appropriate.

.. raw:: html

   </div>