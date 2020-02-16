Import('env')

env.Append(CPPPATH=['./src/h'])

env.VariantDir('build', 'src/c', duplicate=0)
libmap_sources = Glob('build/*.c')
env.SharedLibrary(target = "build/libmap", source = libmap_sources, PDB = "build/libmap.pdb")
