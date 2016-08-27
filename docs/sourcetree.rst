Mesa source code tree overview
==============================

This is a brief summary of Mesa's directory tree and what's contained in
each directory.

-  **docs** - Documentation
-  **include** - Public OpenGL header files
-  **src**

   -  **egl** - EGL library sources

      -  **docs** - EGL documentation
      -  **drivers** - EGL drivers
      -  **main** - main EGL library implementation. This is where all
         the EGL API functions are implemented, like eglCreateContext().

   -  **glsl** - the GLSL compiler
   -  **mapi** - Mesa APIs
   -  **glapi** - OpenGL API dispatch layer. This is where all the GL
      entrypoints like glClear, glBegin, etc. are generated, as well as
      the GL dispatch table. All GL function calls jump through the
      dispatch table to functions found in main/.
   -  **mesa** - Main Mesa sources

      -  **main** - The core Mesa code (mainly state management)
      -  **drivers** - Mesa drivers (not used with Gallium)

         -  **common** - code which may be shared by all drivers
         -  **dri** - Direct Rendering Infrastructure drivers

            -  **common** - code shared by all DRI drivers
            -  **i915** - driver for Intel i915/i945
            -  **i965** - driver for Intel i965
            -  **radeon** - driver for ATI R100
            -  **r200** - driver for ATI R200
            -  XXX more

         -  **x11** - Xlib-based software driver
         -  **osmesa** - off-screen software driver
         -  XXX more

      -  **math** - vertex array translation and transformation code
         (not used with Gallium)
      -  **program** - Vertex/fragment shader and GLSL compiler code
      -  **sparc** - Assembly code/optimizations for SPARC systems (not
         used with Gallium)
      -  **state\_tracker** - State tracker / driver for Gallium. This
         is basically a Mesa device driver that speaks to Gallium. This
         directory may be moved to src/mesa/drivers/gallium at some
         point.
      -  **swrast** - Software rasterization module. For drawing points,
         lines, triangles, bitmaps, images, etc. in software. (not used
         with Gallium)
      -  **swrast\_setup** - Software primitive setup. Does things like
         polygon culling, glPolygonMode, polygon offset, etc. (not used
         with Gallium)
      -  **tnl** - Software vertex Transformation 'n Lighting. (not used
         with Gallium)
      -  **tnl\_dd** - TNL code for device drivers. (not used with
         Gallium)
      -  **vbo** - Vertex Buffer Object code. All drawing with
         glBegin/glEnd, glDrawArrays, display lists, etc. goes through
         this module. The results is a well-defined set of vertex arrays
         which are passed to the device driver (or tnl module) for
         rendering.
      -  **x86** - Assembly code/optimizations for 32-bit x86 systems
         (not used with Gallium)
      -  **x86-64** - Assembly code/optimizations for 64-bit x86 systems
         (not used with Gallium)

   -  **gallium** - Gallium3D source code

      -  **include** - Gallium3D header files which define the Gallium3D
         interfaces
      -  **drivers** - Gallium3D device drivers

         -  **i915** - Driver for Intel i915/i945.
         -  **llvmpipe** - Software driver using LLVM for runtime code
            generation.
         -  **nv\*** - Drivers for NVIDIA GPUs.
         -  **radeonsi** - Driver for AMD Southern Island.
         -  **r300** - Driver for ATI R300 - R500.
         -  **r600** - Driver for ATI/AMD R600 - Northern Island.
         -  **softpipe** - Software reference driver.
         -  **svga** - Driver for VMware's SVGA virtual GPU.
         -  **trace** - Driver for tracing Gallium calls.
         -  XXX more

      -  **auxiliary** - Gallium support code

         -  **draw** - Software vertex processing and primitive assembly
            module. This includes vertex program execution, clipping,
            culling and optional stages for drawing wide lines, stippled
            lines, polygon stippling, two-sided lighting, etc. Intended
            for use by drivers for hardware that does not have vertex
            shaders. Geometry shaders will also be implemented in this
            module.
         -  **cso\_cache** - Constant State Objects Cache. Used to
            filter out redundant state changes between state trackers
            and drivers.
         -  **gallivm** - LLVM module for Gallium. For LLVM-based
            compilation, optimization and code generation for TGSI
            shaders. Incomplete.
         -  **pipebuffer** - utility module for managing buffers
         -  **rbug** - Gallium remote debug utility
         -  **rtasm** - run-time assembly/machine code generation.
            Currently there's run-time code generation for x86/SSE,
            PowerPC and Cell SPU.
         -  **tgsi** - TG Shader Infrastructure. Code for encoding,
            manipulating and interpreting GPU programs.
         -  **translate** - module for translating vertex data from one
            format to another.
         -  **util** - assorted utilities for arithmetic, hashing,
            surface creation, memory management, 2D blitting, simple
            rendering, etc.

      -  **state\_trackers** -

         -  **clover** - OpenCL state tracker
         -  **dri** - Meta state tracker for DRI drivers
         -  **glx** - Meta state tracker for GLX
         -  **vdpau** - VDPAU state tracker
         -  **wgl** -
         -  **xorg** - Meta state tracker for Xorg video drivers
         -  **xvmc** - XvMC state tracker

      -  **winsys** -

         -  **drm** -
         -  **gdi** -
         -  **xlib** -

   -  **glx** - The GLX library code for building libGL. This is used
      for direct rendering drivers. It will dynamically load one of the
      xxx\_dri.so drivers.

-  **lib** - where the GL libraries are placed

.. raw:: html

   </div>