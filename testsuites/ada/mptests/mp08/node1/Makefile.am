include $(RTEMS_ROOT)/make/custom/@RTEMS_BSP@.cfg
include $(top_srcdir)/../automake/compile.am

include $(top_srcdir)/ada.am

AM_ADAFLAGS += -I$(srcdir)/..

noinst_PROGRAMS = mp08_ada_mp08_node1
mp08_ada_mp08_node1_SOURCES = mp08_node1.adb ../mptest.adb config.h
mp08_ada_mp08_node1_SOURCES += ../mptest.ads
mp08_ada_mp08_node1_SOURCES += ../../../support/init.c

mp08_ada_mp08_node1$(EXEEXT): mp08_node1.adb ../mptest.adb init.$(OBJEXT)
	$(GNATCOMPILE) -margs -a $< -o $@

scndir = $(rtems_ada_testsdir)
dist_scn_DATA = ada_mp08-node1.scn

