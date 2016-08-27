Environment Variables
=====================

Normally, no environment variables need to be set. Most of the
environment variables used by Mesa/Gallium are for debugging purposes,
but they can sometimes be useful for debugging end-user issues.

.. rubric:: LibGL environment variables
   :name: libgl-environment-variables

-  LIBGL\_DEBUG - If defined debug information will be printed to
   stderr. If set to 'verbose' additional information will be printed.
-  LIBGL\_DRIVERS\_PATH - colon-separated list of paths to search for
   DRI drivers
-  LIBGL\_ALWAYS\_INDIRECT - forces an indirect rendering
   context/connection.
-  LIBGL\_ALWAYS\_SOFTWARE - if set, always use software rendering
-  LIBGL\_NO\_DRAWARRAYS - if set do not use DrawArrays GLX protocol
   (for debugging)
-  LIBGL\_SHOW\_FPS - print framerate to stdout based on the number of
   glXSwapBuffers calls per second.
-  LIBGL\_DRI3\_DISABLE - disable DRI3 if set (the value does not
   matter)

.. rubric:: Core Mesa environment variables
   :name: core-mesa-environment-variables

-  MESA\_NO\_ASM - if set, disables all assembly language optimizations
-  MESA\_NO\_MMX - if set, disables Intel MMX optimizations
-  MESA\_NO\_3DNOW - if set, disables AMD 3DNow! optimizations
-  MESA\_NO\_SSE - if set, disables Intel SSE optimizations
-  MESA\_DEBUG - if set, error messages are printed to stderr. For
   example, if the application generates a GL\_INVALID\_ENUM error, a
   corresponding error message indicating where the error occurred, and
   possibly why, will be printed to stderr.
   For release builds, MESA\_DEBUG defaults to off (no debug output).
   MESA\_DEBUG accepts the following comma-separated list of named
   flags, which adds extra behaviour to just set MESA\_DEBUG=1:

   -  silent - turn off debug messages. Only useful for debug builds.
   -  flush - flush after each drawing command
   -  incomplete\_tex - extra debug messages when a texture is
      incomplete
   -  incomplete\_fbo - extra debug messages when a fbo is incomplete

-  MESA\_LOG\_FILE - specifies a file name for logging all errors,
   warnings, etc., rather than stderr
-  MESA\_TEX\_PROG - if set, implement conventional texture env modes
   with fragment programs (intended for developers only)
-  MESA\_TNL\_PROG - if set, implement conventional vertex
   transformation operations with vertex programs (intended for
   developers only). Setting this variable automatically sets the
   MESA\_TEX\_PROG variable as well.
-  MESA\_EXTENSION\_OVERRIDE - can be used to enable/disable extensions.
   A value such as "GL\_EXT\_foo -GL\_EXT\_bar" will enable the
   GL\_EXT\_foo extension and disable the GL\_EXT\_bar extension.
-  MESA\_EXTENSION\_MAX\_YEAR - The GL\_EXTENSIONS string returned by
   Mesa is sorted by extension year. If this variable is set to year X,
   only extensions defined on or before year X will be reported. This is
   to work-around a bug in some games where the extension string is
   copied into a fixed-size buffer without truncating. If the extension
   string is too long, the buffer overrun can cause the game to crash.
   This is a work-around for that.
-  MESA\_GL\_VERSION\_OVERRIDE - changes the value returned by
   glGetString(GL\_VERSION) and possibly the GL API type.

   -  The format should be MAJOR.MINOR[FC]
   -  FC is an optional suffix that indicates a forward compatible
      context. This is only valid for versions >= 3.0.
   -  GL versions < 3.0 are set to a compatibility (non-Core) profile
   -  GL versions = 3.0, see below
   -  GL versions > 3.0 are set to a Core profile
   -  Examples: 2.1, 3.0, 3.0FC, 3.1, 3.1FC

      -  2.1 - select a compatibility (non-Core) profile with GL version
         2.1
      -  3.0 - select a compatibility (non-Core) profile with GL version
         3.0
      -  3.0FC - select a Core+Forward Compatible profile with GL
         version 3.0
      -  3.1 - select a Core profile with GL version 3.1
      -  3.1FC - select a Core+Forward Compatible profile with GL
         version 3.1

   -  Mesa may not really implement all the features of the given
      version. (for developers only)

-  MESA\_GLES\_VERSION\_OVERRIDE - changes the value returned by
   glGetString(GL\_VERSION) for OpenGL ES.

   -  The format should be MAJOR.MINOR
   -  Examples: 2.0, 3.0, 3.1
   -  Mesa may not really implement all the features of the given
      version. (for developers only)

-  MESA\_GLSL\_VERSION\_OVERRIDE - changes the value returned by
   glGetString(GL\_SHADING\_LANGUAGE\_VERSION). Valid values are
   integers, such as "130". Mesa will not really implement all the
   features of the given language version if it's higher than what's
   normally reported. (for developers only)
-  MESA\_GLSL - `shading language compiler
   options <shading.html#envvars>`__
-  MESA\_NO\_MINMAX\_CACHE - when set, the minmax index cache is
   globally disabled.

.. rubric:: Mesa Xlib driver environment variables
   :name: mesa-xlib-driver-environment-variables

The following are only applicable to the Mesa Xlib software driver. See
the `Xlib software driver page <xlibdriver.html>`__ for details.

-  MESA\_RGB\_VISUAL - specifies the X visual and depth for RGB mode
-  MESA\_CI\_VISUAL - specifies the X visual and depth for CI mode
-  MESA\_BACK\_BUFFER - specifies how to implement the back color
   buffer, either "pixmap" or "ximage"
-  MESA\_GAMMA - gamma correction coefficients for red, green, blue
   channels
-  MESA\_XSYNC - enable synchronous X behavior (for debugging only)
-  MESA\_GLX\_FORCE\_CI - if set, force GLX to treat 8bpp visuals as CI
   visuals
-  MESA\_GLX\_FORCE\_ALPHA - if set, forces RGB windows to have an alpha
   channel.
-  MESA\_GLX\_DEPTH\_BITS - specifies default number of bits for depth
   buffer.
-  MESA\_GLX\_ALPHA\_BITS - specifies default number of bits for alpha
   channel.

.. rubric:: i945/i965 driver environment variables (non-Gallium)
   :name: i945i965-driver-environment-variables-non-gallium

-  INTEL\_NO\_HW - if set to 1, prevents batches from being submitted to
   the hardware. This is useful for debugging hangs, etc.
-  INTEL\_DEBUG - a comma-separated list of named flags, which do
   various things:

   -  tex - emit messages about textures.
   -  state - emit messages about state flag tracking
   -  blit - emit messages about blit operations
   -  miptree - emit messages about miptrees
   -  perf - emit messages about performance issues
   -  perfmon - emit messages about AMD\_performance\_monitor
   -  bat - emit batch information
   -  pix - emit messages about pixel operations
   -  buf - emit messages about buffer objects
   -  fbo - emit messages about framebuffers
   -  fs - dump shader assembly for fragment shaders
   -  gs - dump shader assembly for geometry shaders
   -  sync - after sending each batch, emit a message and wait for that
      batch to finish rendering
   -  prim - emit messages about drawing primitives
   -  vert - emit messages about vertex assembly
   -  dri - emit messages about the DRI interface
   -  sf - emit messages about the strips & fans unit (for old gens,
      includes the SF program)
   -  stats - enable statistics counters. you probably actually want
      perfmon or intel\_gpu\_top instead.
   -  urb - emit messages about URB setup
   -  vs - dump shader assembly for vertex shaders
   -  clip - emit messages about the clip unit (for old gens, includes
      the CLIP program)
   -  aub - dump batches into an AUB trace for use with simulation tools
   -  shader\_time - record how much GPU time is spent in each shader
   -  no16 - suppress generation of 16-wide fragment shaders. useful for
      debugging broken shaders
   -  blorp - emit messages about the blorp operations (blits & clears)
   -  nodualobj - suppress generation of dual-object geometry shader
      code
   -  optimizer - dump shader assembly to files at each optimization
      pass and iteration that make progress
   -  ann - annotate IR in assembly dumps
   -  no8 - don't generate SIMD8 fragment shader
   -  vec4 - force vec4 mode in vertex shader
   -  spill\_fs - force spilling of all registers in the scalar backend
      (useful to debug spilling code)
   -  spill\_vec4 - force spilling of all registers in the vec4 backend
      (useful to debug spilling code)
   -  cs - dump shader assembly for compute shaders
   -  hex - print instruction hex dump with the disassembly
   -  nocompact - disable instruction compaction
   -  tcs - dump shader assembly for tessellation control shaders
   -  tes - dump shader assembly for tessellation evaluation shaders
   -  l3 - emit messages about the new L3 state during transitions
   -  do32 - generate compute shader SIMD32 programs even if workgroup
      size doesn't exceed the SIMD16 limit
   -  norbc - disable single sampled render buffer compression

.. rubric:: Radeon driver environment variables (radeon, r200, and
   r300g)
   :name: radeon-driver-environment-variables-radeon-r200-and-r300g

-  RADEON\_NO\_TCL - if set, disable hardware-accelerated
   Transform/Clip/Lighting.

.. rubric:: EGL environment variables
   :name: egl-environment-variables

Mesa EGL supports different sets of environment variables. See the `Mesa
EGL <egl.html>`__ page for the details.

.. rubric:: Gallium environment variables
   :name: gallium-environment-variables

-  GALLIUM\_HUD - draws various information on the screen, like
   framerate, cpu load, driver statistics, performance counters, etc.
   Set GALLIUM\_HUD=help and run e.g. glxgears for more info.
-  GALLIUM\_HUD\_PERIOD - sets the hud update rate in seconds (float).
   Use zero to update every frame. The default period is 1/2 second.
-  GALLIUM\_HUD\_VISIBLE - control default visibility, defaults to true.
-  GALLIUM\_HUD\_TOGGLE\_SIGNAL - toggle visibility via user specified
   signal. Especially useful to toggle hud at specific points of
   application and disable for unencumbered viewing the rest of the
   time. For example, set GALLIUM\_HUD\_VISIBLE to false and
   GALLIUM\_HUD\_SIGNAL\_TOGGLE to 10 (SIGUSR1). Use kill -10 to toggle
   the hud as desired.
-  GALLIUM\_LOG\_FILE - specifies a file for logging all errors,
   warnings, etc. rather than stderr.
-  GALLIUM\_PRINT\_OPTIONS - if non-zero, print all the Gallium
   environment variables which are used, and their current values.
-  GALLIUM\_DUMP\_CPU - if non-zero, print information about the CPU on
   start-up
-  TGSI\_PRINT\_SANITY - if set, do extra sanity checking on TGSI
   shaders and print any errors to stderr.
-  DRAW\_FSE - ???
-  DRAW\_NO\_FSE - ???
-  DRAW\_USE\_LLVM - if set to zero, the draw module will not use LLVM
   to execute shaders, vertex fetch, etc.
-  ST\_DEBUG - controls debug output from the Mesa/Gallium state
   tracker. Setting to "tgsi", for example, will print all the TGSI
   shaders. See src/mesa/state\_tracker/st\_debug.c for other options.

.. rubric:: Softpipe driver environment variables
   :name: softpipe-driver-environment-variables

-  SOFTPIPE\_DUMP\_FS - if set, the softpipe driver will print fragment
   shaders to stderr
-  SOFTPIPE\_DUMP\_GS - if set, the softpipe driver will print geometry
   shaders to stderr
-  SOFTPIPE\_NO\_RAST - if set, rasterization is no-op'd. For profiling
   purposes.
-  SOFTPIPE\_USE\_LLVM - if set, the softpipe driver will try to use
   LLVM JIT for vertex shading processing.

.. rubric:: LLVMpipe driver environment variables
   :name: llvmpipe-driver-environment-variables

-  LP\_NO\_RAST - if set LLVMpipe will no-op rasterization
-  LP\_DEBUG - a comma-separated list of debug options is accepted. See
   the source code for details.
-  LP\_PERF - a comma-separated list of options to selectively no-op
   various parts of the driver. See the source code for details.
-  LP\_NUM\_THREADS - an integer indicating how many threads to use for
   rendering. Zero turns off threading completely. The default value is
   the number of CPU cores present.

.. rubric:: VMware SVGA driver environment variables
   :name: vmware-svga-driver-environment-variables

-  SVGA\_FORCE\_SWTNL - force use of software vertex transformation
-  SVGA\_NO\_SWTNL - don't allow software vertex transformation
   fallbacks (will often result in incorrect rendering).
-  SVGA\_DEBUG - for dumping shaders, constant buffers, etc. See the
   code for details.
-  See the driver code for other, lesser-used variables.

.. rubric:: VA-API state tracker environment variables
   :name: va-api-state-tracker-environment-variables

-  VAAPI\_MPEG4\_ENABLED - enable MPEG4 for VA-API, disabled by default.

.. rubric:: VC4 driver environment variables
   :name: vc4-driver-environment-variables

-  VC4\_DEBUG - a comma-separated list of named flags, which do various
   things:

   -  cl - dump command list during creation
   -  qpu - dump generated QPU instructions
   -  qir - dump QPU IR during program compile
   -  nir - dump NIR during program compile
   -  tgsi - dump TGSI during program compile
   -  shaderdb - dump program compile information for shader-db analysis
   -  perf - print during performance-related events
   -  norast - skip actual hardware execution of commands
   -  always\_flush - flush after each draw call
   -  always\_sync - wait for finish after each flush
   -  dump - write a GPU command stream trace file (VC4 simulator only)

Other Gallium drivers have their own environment variables. These may
change frequently so the source code should be consulted for details.

.. raw:: html

   </div>