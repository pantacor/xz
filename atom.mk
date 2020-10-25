LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := xz
LOCAL_DESCRIPTION := xz and liblzma

LOCAL_EXPORT_LDLIBS = -l:liblzma.a

LOCAL_AUTOTOOLS_VERSION := 2.0.4
LOCAL_AUTOTOOLS_CONFIGURE_ARGS := 
LOCAL_AUTOTOOLS_CONFIGURE_ENV :=


#LOCAL_CLEAN_DIRS := $(call local-get-build-dir)/usr/share/ $(call local-get-build-dir)/usr/include/

include $(BUILD_AUTOTOOLS)

