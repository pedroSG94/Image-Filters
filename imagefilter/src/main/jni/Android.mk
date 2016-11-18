LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS    := -lm -llog -ljnigraphics
LOCAL_MODULE := libImageFilter
LOCAL_SRC_FILES := libImageFilter.cpp
LOCAL_C_INCLUDES :=
include $(BUILD_SHARED_LIBRARY)