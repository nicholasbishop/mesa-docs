llvmpipe
========

The Gallium llvmpipe driver is a software rasterizer that uses LLVM to
do runtime code generation. Shaders, point/line/triangle rasterization
and vertex processing are implemented with LLVM IR which is translated
to x86 or x86-64 machine code. Also, the driver is multithreaded to take
advantage of multiple CPU cores (up to 8 at this time). It's the fastest
software rasterizer for Mesa.

.. rubric:: Requirements
   :name: requirements

-  An x86 or amd64 processor; 64-bit mode recommended.

   Support for SSE2 is strongly encouraged. Support for SSSE3 and SSE4.1
   will yield the most efficient code. The fewer features the CPU has
   the more likely is that you run into underperforming, buggy, or
   incomplete code.

   See /proc/cpuinfo to know what your CPU supports.

-  LLVM: version 3.4 recommended; 3.3 or later required.

   For Linux, on a recent Debian based distribution do:

   ::

            aptitude install llvm-dev

   For a RPM-based distribution do:

   ::

            yum install llvm-devel

   For Windows you will need to build LLVM from source with MSVC or
   MINGW (either natively or through cross compilers) and CMake, and set
   the LLVM environment variable to the directory you installed it to.
   LLVM will be statically linked, so when building on MSVC it needs to
   be built with a matching CRT as Mesa, and you'll need to pass
   ``-DLLVM_USE_CRT_xxx=yyy`` as described below.

   LLVM build-type

   Mesa build-type

   debug,checked

   release,profile

   Debug

   ``-DLLVM_USE_CRT_DEBUG=MTd``

   ``-DLLVM_USE_CRT_DEBUG=MT``

   Release

   ``-DLLVM_USE_CRT_RELEASE=MTd``

   ``-DLLVM_USE_CRT_RELEASE=MT``

   You can build only the x86 target by passing
   -DLLVM\_TARGETS\_TO\_BUILD=X86 to cmake.

-  scons (optional)

.. rubric:: Building
   :name: building

To build everything on Linux invoke scons as:
::

      scons build=debug libgl-xlib

Alternatively, you can build it with GNU make, if you prefer, by
invoking it as
::

      make linux-llvm

but the rest of these instructions assume that scons is used. For
Windows the procedure is similar except the target:
::

      scons platform=windows build=debug libgl-gdi

.. rubric:: Using
   :name: using

.. rubric:: Linux
   :name: linux

On Linux, building will create a drop-in alternative for libGL.so into

::

      build/foo/gallium/targets/libgl-xlib/libGL.so

or::

      lib/gallium/libGL.so

To use it set the LD\_LIBRARY\_PATH environment variable accordingly.

For performance evaluation pass build=release to scons, and use the
corresponding lib directory without the "-debug" suffix.

.. rubric:: Windows
   :name: windows

On Windows, building will create
``build/windows-x86-debug/gallium/targets/libgl-gdi/opengl32.dll`` which
is a drop-in alternative for system's ``opengl32.dll``. To use it put it
in the same directory as your application. It can also be used by
replacing the native ICD driver, but it's quite an advanced usage, so if
you need to ask, don't even try it.

There is however an easy way to replace the OpenGL software renderer
that comes with Microsoft Windows 7 (or later) with llvmpipe (that is,
on systems without any OpenGL drivers):

-  copy build/windows-x86-debug/gallium/targets/libgl-gdi/opengl32.dll
   to C:\\Windows\\SysWOW64\\mesadrv.dll

-  load this registry settings:

   ::

       REGEDIT4

       ; http://technet.microsoft.com/en-us/library/cc749368.aspx
       ; http://www.msfn.org/board/topic/143241-portable-windows-7-build-from-winpe-30/page-5#entry942596
       [HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows NT\CurrentVersion\OpenGLDrivers\MSOGL]
       "DLL"="mesadrv.dll"
       "DriverVersion"=dword:00000001
       "Flags"=dword:00000001
       "Version"=dword:00000002

-  Ditto for 64 bits drivers if you need them.

.. rubric:: Profiling
   :name: profiling

To profile llvmpipe you should build as

::

      scons build=profile <same-as-before>

This will ensure that frame pointers are used both in C and JIT
functions, and that no tail call optimizations are done by gcc.

.. rubric:: Linux perf integration
   :name: linux-perf-integration

On Linux, it is possible to have symbol resolution of JIT code with
`Linux perf <http://perf.wiki.kernel.org/>`__:

::

        perf record -g /my/application
        perf report

When run inside Linux perf, llvmpipe will create a /tmp/perf-XXXXX.map
file with symbol address table. It also dumps assembly code to
/tmp/perf-XXXXX.map.asm, which can be used by the bin/perf-annotate-jit
script to produce disassembly of the generated code annotated with the
samples.

You can obtain a call graph via
`Gprof2Dot <http://code.google.com/p/jrfonseca/wiki/Gprof2Dot#linux_perf>`__.

.. rubric:: Unit testing
   :name: unit-testing

Building will also create several unit tests in
build/linux-???-debug/gallium/drivers/llvmpipe:

-  lp\_test\_blend: blending
-  lp\_test\_conv: SIMD vector conversion
-  lp\_test\_format: pixel unpacking/packing

Some of this tests can output results and benchmarks to a
tab-separated-file for posterior analysis, e.g.:

::

      build/linux-x86_64-debug/gallium/drivers/llvmpipe/lp_test_blend -o blend.tsv

.. rubric:: Development Notes
   :name: development-notes

-  When looking to this code by the first time start in lp\_state\_fs.c,
   and then skim through the lp\_bld\_\* functions called in there, and
   the comments at the top of the lp\_bld\_\*.c functions.
-  The driver-independent parts of the LLVM / Gallium code are found in
   src/gallium/auxiliary/gallivm/. The filenames and function prefixes
   need to be renamed from "lp\_bld\_" to something else though.
-  We use LLVM-C bindings for now. They are not documented, but follow
   the C++ interfaces very closely, and appear to be complete enough for
   code generation. See `this stand-alone
   example <http://npcontemplation.blogspot.com/2008/06/secret-of-llvm-c-bindings.html>`__.
   See the llvm-c/Core.h file for reference.

.. rubric:: Recommended Reading
   :name: recommended_reading

-  Rasterization

   -  `Triangle Scan Conversion using 2D Homogeneous
      Coordinates <http://www.cs.unc.edu/~olano/papers/2dh-tri/>`__
   -  `Rasterization on
      Larrabee <http://www.drdobbs.com/parallel/rasterization-on-larrabee/217200602>`__
      (`DevMaster
      copy <http://devmaster.net/posts/2887/rasterization-on-larrabee>`__)
   -  `Rasterization using half-space
      functions <http://devmaster.net/posts/6133/rasterization-using-half-space-functions>`__
   -  `Advanced
      Rasterization <http://devmaster.net/posts/6145/advanced-rasterization>`__
   -  `Optimizing Software Occlusion
      Culling <http://fgiesen.wordpress.com/2013/02/17/optimizing-sw-occlusion-culling-index/>`__

-  Texture sampling

   -  `Perspective Texture
      Mapping <http://chrishecker.com/Miscellaneous_Technical_Articles#Perspective_Texture_Mapping>`__
   -  `Texturing As In
      Unreal <http://www.flipcode.com/archives/Texturing_As_In_Unreal.shtml>`__
   -  `Run-Time MIP-Map
      Filtering <http://www.gamasutra.com/view/feature/3301/runtime_mipmap_filtering.php>`__
   -  `Will "brilinear" filtering
      persist? <http://alt.3dcenter.org/artikel/2003/10-26_a_english.php>`__
   -  `Trilinear
      filtering <http://ixbtlabs.com/articles2/gffx/nv40-rx800-3.html>`__
   -  `Texture
      Swizzling <http://devmaster.net/posts/12785/texture-swizzling>`__

-  SIMD

   -  `Whole-Function
      Vectorization <http://www.cdl.uni-saarland.de/projects/wfv/#header4>`__

-  Optimization

   -  `Optimizing Pixomatic For Modern x86
      Processors <http://www.drdobbs.com/optimizing-pixomatic-for-modern-x86-proc/184405807>`__
   -  `Intel 64 and IA-32 Architectures Optimization Reference
      Manual <http://www.intel.com/content/www/us/en/architecture-and-technology/64-ia-32-architectures-optimization-manual.html>`__
   -  `Software optimization
      resources <http://www.agner.org/optimize/>`__
   -  `Intel Intrinsics
      Guide <http://software.intel.com/en-us/articles/intel-intrinsics-guide>`__
   -  

-  LLVM

   -  `LLVM Language Reference
      Manual <http://llvm.org/docs/LangRef.html>`__
   -  `The secret of LLVM C
      bindings <http://npcontemplation.blogspot.co.uk/2008/06/secret-of-llvm-c-bindings.html>`__

-  General

   -  `A trip through the Graphics
      Pipeline <http://fgiesen.wordpress.com/2011/07/09/a-trip-through-the-graphics-pipeline-2011-index/>`__
   -  `WARP Architecture and
      Performance <http://msdn.microsoft.com/en-us/library/gg615082.aspx#architecture>`__

.. raw:: html

   </div>
