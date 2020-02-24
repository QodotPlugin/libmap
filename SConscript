#!python
import os, subprocess

Import('env')
env = env.Clone()

env.Append(CPPPATH=['./src/h'])

if env['platform'] == "osx":
    env.Append(LINKFLAGS = [
        '-install_name',
        '@loader_path/libmap.dylib'
    ])

env.VariantDir('build', 'src/c', duplicate=0)
libmap_sources = Glob('build/*.c')
env.SharedLibrary(target = "build/libmap", source = libmap_sources, PDB = "build/libmap.pdb")
