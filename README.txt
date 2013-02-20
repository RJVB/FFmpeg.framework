This is an Xcode project file that allows to create a standalone, monolithic framework from the static libraries of an existing FFmpeg installation. It is configured to expect the +nonfree+universal variant of the MacPorts repository, installed in (accessible through) that project's default installation directory, /opt/local .

The central build target is FFmpegFW-mp (mp standing for MacPorts).

The build procedure is as follows
- a script catches the initial list of files to be linked. It then retrieves the various FFmpeg static libraries, extracting the i386 and x86_64 archives. Duplicate entries for log2_tab.o are deleted where relevant. A new master link object file is then created from the libraries, using ld -r -all_load , and the original LinkFileList replaced by one containing that master object, plus any objects mentioned originally but not yet present on disk.
- Another script copies the header files from the MacPorts tree into the framework bundle.
- During the final link step, Xcode links in the various libraries required, and generates a framework.

The project is set up to be placed in a subdirectory of the FFmpeg source repository as can be downloaded via git, but the source files are only used for reference, EXCEPT FOR the License file. Its absence should not be a problem.
It is possible to modify the initial script to use self-compiled libraries, extracting the install location from the build files. In that case you will have to check to make sure the correct external libraries are linked. NB: when adding libraries to a target’s dependencies, Xcode will add the location to the library search path; it will not remove those entries when the corresponding libraries are removed!