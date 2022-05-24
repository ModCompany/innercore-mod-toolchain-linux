# Toolchain Linux Updated
 This version without python-setup.py for building toolchain      
 Features of this Version on Linux:
 - Added Debug Log (Dump log throught ADB)
 - Added Dump Crash Log(Dump crash log)
 - Fixed all bat and python.py scripts
 - Fixed Java / Js / Native compiles 

To work properly this toolchain requires:
 - [Python](https://www.python.org/) 3.6 or higher
 - [node.js](https://nodejs.org/en/) 10.15.1 or higher (for typescript modding), you need to have `tsc` installed (to install run `npm install -g tsc`)
 - Valid [Android NDK](https://developer.android.com/ndk/downloads/older_releases) installation (for native modding). Preferred version is r16b
 - [Java Development Kit 1.8](https://www.oracle.com/java/technologies/javase/javase-jdk8-downloads.html) or higher (for Java modding) 

## How to Install toolchain on Manjaro:
*&#46;First of all you need to update your packages*
 ```
 - pacman -Syy
 ```
*&#46;After update your packages you need to download python 3.10 or above version*
 ```
 - pacman -S python
 ```
 *&#46;After installing check version of python*
 ```
 - python
 #For leave python compiler you need to write quit() or CTRL + D
 ```
*&#46;Next step is install nodejs*
```
 - pacman -S nodejs npm
```

*&#46;Next step is install typescript from npm for compile .js / .ts files in toolchain*
```
 - npm install -g typescript
```
*&#46;Next step is installing jdk 1.8 you can download form internet for linux package*
```
#You need to place jdk folder to /usr/lib/jvm/<Your JDK> and set from konsole/terminal archlinux-java set folder_name
```

*&#46;After all of this actions you can download ndk*
## For VSCODE:
(*CTRL+SHIFT+B*) **Build and Compile Native** task.This task compile js files and download NDK from google repository
## For Terminal:
```
cd toolchain
sh compile-native.sh
```
## First Build

To run your first build, run (*Ctrl+Shift+B*) **Build and Push Everything** task. This task performs the required setup and builds the whole project. If your project contains native code, local NDK installation will be created. This can take some time.

## make.json

*make.json* is the main configuration file of the project. In this file you can specify everything you need to build a mod for Inner Core. Most of the work, such as scripts generation and *build.config* creation is done under the hood. 

Here's a description of some of the key properties you can specify in your *make.json*:
 - **global&#46;info** contains information about the mod name, author, version and description. The information is stored in the corresponding fields
 - **global&#46;api** specifies what JavaScript API is used in the mod by default
 - **make** contains information about what libraries should be linked and what ABIs should the project target. You generally don't want to change these settings
 - **resources** specifies what resources should be included in the output mod. There are currently four resource types available:  
   - *resource_directory* contains textures to use in Minecraft
   - *gui* contains all the gui textures
   - *minecraft_resource_pack* contains vanilla resource packs to be used with the mod
   - *minecraft_behavior_pack* contains vanilla behavior packs to be used with the mod
 - **sources** specifies what JavaScript files should be included (or built) into the mod build. Every source can be a file, a list of files specified by wildcards or a directory containing .includes file. There are currently four types of sources: 
   - *main* contains main mod logic
   - *launcher* contains mod launching logics
   - *preloader* is run before resources injection. This is useful to generate resources programmatically before Minecraft loads them
   - *lib* contains reusable mod libraries
 - There are also two supported languages:
   - *javascript* is used for pure javascript project using ES5 language standart. These folders are not compiled and are just built 'as is'.
   - *typescript* is used for typescript language and ESNext version of Javascript. These folders are built using typescript compiler.
 - **compile** specifies all the source code that should be compiled. This toolchain currently supports two compilation types:
   - *native* is used to compile C/C++ sources. Note that Android NDK is required to run this type of compilation
   - *java* is used to compile Java sources. Note that you have to install JDK of version 1.8 or higher to run this type of compilation
 - **additional** contains additional directories that should be copied to the mod build. In this example, root directory is copied to the root of the mod

## Documentation and Further Resources

All the documentation is available at https://docs.mineprogramming.org

Some of the old (but mostly still applicable) information can be found at https://wiki.mineprogramming.org

To update your local typescript header files (used for hints in JavaScript files), go to https://github.com/zheka2304/innercore-mod-toolchain, download everything from *toolchain/jslibs* and unpack to your local *toolchain/jslibs* folder. The documentation is a subject to regular updates, so be sure to use the latest features it provides 😉

## Adding Java directories

By default this toolchain doesn't contain java modules to minimize build time. However, if you need to include a java module into your mod, follow the instructions below. 

Unpack *java.zip* archive to the root of mod source. You will get the following files structure:

```
.
└─ src
   ├─...
   └─ java
   │  └─ sample
   │     ├─ lib
   │     ├─ src
   │     │  └─ com
   │     │     └─ sample_mod
   │     │        └─ sample_package
   │     │           └─ Boot.java
   │     └─ manifest
   └─ .classpath
```
In the example above, a sample java module is already created. To add a new one, create a directory in *java* folder and add it to 
*.classpath* file as a new entry:

```xml
<classpathentry kind="src" path="src/java/module_name/src"/>
```

To add *.jar* libraries to classpath and to the compiler, move your library file
to the *libs* directory and add a new entry to the *.classpath* file:

```xml
<classpathentry kind="lib" path="src/java/sample/lib/lib_name.jar"/>
```

## Working with Android Debug Bridge

Android Debug Bridge allows this toolchain to push mod files to the remote device and to launch Horizon via USB cable. You can specify push path in the **make.pushTo** property in your *make.json*. When you run the appropriate build task (*Ctrl+Shift+B*), only the files that were changed are being pushed. 

## Building and Publishing a Release Version of the Mod

To build a release version of the mod, run **Assemble Mod for Release** task. An *.icmod* archive is being generated and is ready for upload. Go to https://icmods.mineprogramming.org and upload a new mod or update an existing one.

![](https://komarev.com/ghpvc/?username=ModCompany)

