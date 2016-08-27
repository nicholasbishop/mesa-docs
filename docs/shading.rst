Shading Language Support
========================

This page describes the features and status of Mesa's support for the
`OpenGL Shading Language <http://opengl.org/documentation/glsl/>`__.

Contents

-  `Environment variables <#envvars>`__
-  `GLSL 1.40 support <#support>`__
-  `Unsupported Features <#unsup>`__
-  `Implementation Notes <#notes>`__
-  `Programming Hints <#hints>`__
-  `Stand-alone GLSL Compiler <#standalone>`__
-  `Compiler Implementation <#implementation>`__
-  `Compiler Validation <#validation>`__

.. rubric:: Environment Variables
   :name: envvars

The **MESA\_GLSL** environment variable can be set to a comma-separated
list of keywords to control some aspects of the GLSL compiler and shader
execution. These are generally used for debugging.

-  **dump** - print GLSL shader code to stdout at link time
-  **log** - log all GLSL shaders to files. The filenames will be
   "shader\_X.vert" or "shader\_X.frag" where X the shader ID.
-  **nopt** - disable compiler optimizations
-  **opt** - force compiler optimizations
-  **uniform** - print message to stdout when glUniform is called
-  **nopvert** - force vertex shaders to be a simple shader that just
   transforms the vertex position with ftransform() and passes through
   the color and texcoord[0] attributes.
-  **nopfrag** - force fragment shader to be a simple shader that passes
   through the color attribute.
-  **useprog** - log glUseProgram calls to stderr

Example: export MESA\_GLSL=dump,nopt

Shaders can be dumped and replaced on runtime for debugging purposes.
Mesa needs to be configured with '--with-sha1' to enable this
functionality. This feature is not currently supported by SCons build.
This is controlled via following environment variables:

-  **MESA\_SHADER\_DUMP\_PATH** - path where shader sources are dumped
-  **MESA\_SHADER\_READ\_PATH** - path where replacement shaders are
   read

Note, path set must exist before running for dumping or replacing to
work. When both are set, these paths should be different so the dumped
shaders do not clobber the replacement shaders.
.. rubric:: GLSL Version
   :name: support

The GLSL compiler currently supports version 3.30 of the shading
language.

Several GLSL extensions are also supported:

-  GL\_ARB\_draw\_buffers
-  GL\_ARB\_fragment\_coord\_conventions
-  GL\_ARB\_shader\_bit\_encoding

.. rubric:: Unsupported Features
   :name: unsup

XXX update this section

The following features of the shading language are not yet fully
supported in Mesa:

-  Linking of multiple shaders does not always work. Currently, linking
   is implemented through shader concatenation and re-compiling. This
   doesn't always work because of some #pragma and preprocessor issues.
-  The gl\_Color and gl\_SecondaryColor varying vars are interpolated
   without perspective correction

All other major features of the shading language should function.

.. rubric:: Implementation Notes
   :name: notes

-  Shading language programs are compiled into low-level programs very
   similar to those of GL\_ARB\_vertex/fragment\_program.
-  All vector types (vec2, vec3, vec4, bvec2, etc) currently occupy full
   float[4] registers.
-  Float constants and variables are packed so that up to four floats
   can occupy one program parameter/register.
-  All function calls are inlined.
-  Shaders which use too many registers will not compile.
-  The quality of generated code is pretty good, register usage is fair.
-  Shader error detection and reporting of errors (InfoLog) is not very
   good yet.
-  The ftransform() function doesn't necessarily match the results of
   fixed-function transformation.

These issues will be addressed/resolved in the future.

.. rubric:: Programming Hints
   :name: hints

-  Use the built-in library functions whenever possible. For example,
   instead of writing this:

   ::

               float x = 1.0 / sqrt(y);

   Write this:

   ::

               float x = inversesqrt(y);

.. rubric:: Stand-alone GLSL Compiler
   :name: standalone

The stand-alone GLSL compiler program can be used to compile GLSL
shaders into low-level GPU code.

This tool is useful for:

-  Inspecting GPU code to gain insight into compilation
-  Generating initial GPU code for subsequent hand-tuning
-  Debugging the GLSL compiler itself

After building Mesa, the compiler can be found at
src/glsl/glsl\_compiler

Here's an example of using the compiler to compile a vertex shader and
emit GL\_ARB\_vertex\_program-style instructions:

::

        src/glsl/glsl_compiler --dump-ast myshader.vert

Options include

-  **--dump-ast** - dump GPU code
-  **--dump-hir** - dump high-level IR code
-  **--dump-lir** - dump low-level IR code
-  **--link** - ???

.. rubric:: Compiler Implementation
   :name: implementation

The source code for Mesa's shading language compiler is in the
``src/glsl/`` directory.

XXX provide some info about the compiler....

The final vertex and fragment programs may be interpreted in software
(see prog\_execute.c) or translated into a specific hardware
architecture (see drivers/dri/i915/i915\_fragprog.c for example).

.. rubric:: Compiler Validation
   :name: validation

Developers working on the GLSL compiler should test frequently to avoid
regressions.

The `Piglit <http://piglit.freedesktop.org/>`__ project has many GLSL
tests.

The Mesa demos repository also has some good GLSL tests.

.. raw:: html

   </div>