AC_INIT([microlc], [0.1], [gvernardos@amnh.org])
AC_LANG(C++)
AC_CONFIG_AUX_DIR(aux-dist)
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_MACRO_DIRS([m4])
AC_PREFIX_DEFAULT($PWD)

AC_PROG_CXX

LT_INIT([disable-static])



##########################################################################
ac_new_CPPFLAGS="-Iinclude -I./include/"
ac_new_LDFLAGS=""
ac_new_LIBS=""

AC_ARG_WITH([jsoncpp],
    [AS_HELP_STRING([--with-jsoncpp=prefix],[give the path to the jsoncpp library and header files.])],
    [
	ac_new_CPPFLAGS+=" -I${withval}/include"
	ac_new_LDFLAGS+=" -L${withval}/lib -Wl,-rpath -Wl,${withval}/lib"
	ac_new_LIBS+=" -ljsoncpp"
    ],
    [
	AC_CHECK_LIB(jsoncpp,main,[],[AC_MSG_ERROR("you need to have the jsoncpp library installed.")])
	AC_CHECK_HEADERS(json/json.h,[],[AC_MSG_ERROR("you need to have the jsoncpp header files installed.")])
    ])

AC_ARG_WITH([CCfits],
    [AS_HELP_STRING([--with-CCfits=prefix],[give the path to the CCfits library and header files.])],
    [
	ac_new_CPPFLAGS+=" -I${withval}/include"
	ac_new_LDFLAGS+=" -L${withval}/lib -Wl,-rpath -Wl,${withval}/lib"
	ac_new_LIBS+=" -lCCfits"
    ],
    [
	AC_CHECK_LIB(CCfits,main,[],[AC_MSG_ERROR("you need to have the CCfits library installed.")],[-lcfitsio])
	AC_CHECK_HEADERS(CCfits/CCfits.h,[],[AC_MSG_ERROR("you need to have the CCfits header files installed.")])
    ])

AC_ARG_WITH([cfitsio],
    [AS_HELP_STRING([--with-cfitsio=prefix],[give the path to the cfitsio library and header files.])],
    [
	ac_new_CPPFLAGS+=" -I${withval}/include"
	ac_new_LDFLAGS+=" -L${withval}/lib -Wl,-rpath -Wl,${withval}/lib"
	ac_new_LIBS+=" -lcfitsio"
    ],
    [
	AC_CHECK_LIB(cfitsio,main,[],[AC_MSG_ERROR("you need to have the cfitsio library installed.")])
	AC_CHECK_HEADERS(fitsio.h,[],[AC_MSG_ERROR("you need to have the cfitsio header files installed.")])
    ])

AC_ARG_WITH([png],
    [AS_HELP_STRING([--with-png=prefix],[give the path to the png library and header files.])],
    [
	ac_new_CPPFLAGS+=" -I${withval}/include"
	ac_new_LDFLAGS+=" -L${withval}/lib -Wl,-rpath -Wl,${withval}/lib"
	ac_new_LIBS+=" -lpng"
    ],
    [
	AC_CHECK_LIB(png,main,[],[AC_MSG_ERROR("you need to have the png library installed.")])
	AC_CHECK_HEADERS(png.h,[],[AC_MSG_ERROR("you need to have the png header files installed.")])
    ])

CPPFLAGS+="$ac_new_CPPFLAGS"
LDFLAGS+="$ac_new_LDFLAGS"
LIBS+="$ac_new_LIBS"

AC_SUBST([CPPFLAGS])
AC_SUBST([LDFLAGS])
AC_SUBST([LIBS])
##########################################################################


##########################################################################
AC_ARG_WITH([map-path],
    [AS_HELP_STRING([--with-map-path=prefix],[give the path to the gerlumph maps])],
    [MAP_PATHSET=1],
    [MAP_PATHSET=0])
	
# if optional parameter used, extend path flags for compliler and linker
if test $MAP_PATHSET = 1 ; then
    MAP_PATH="$with_map_path"
else
    AC_MSG_ERROR([You need to provide the MAP_PATH to comile the gerlumph++ library!])
fi

AC_SUBST([MAP_PATH])
##########################################################################


##########################################################################
CUDA_CFLAGS="-std=c++11 --compiler-options '-fPIC' -Wno-deprecated-gpu-targets"
CUDA_FLAGS="-Xcudafe --diag_suppress=611"
CUDA_LIBS="-lcudart -lcufft"
NVCC="nvcc"

AC_SUBST(CUDA_CFLAGS)
AC_SUBST(CUDA_FLAGS)
AC_SUBST(CUDA_LIBS)
AC_SUBST(NVCC)
##########################################################################


AC_CONFIG_FILES([Makefile])

AC_OUTPUT
