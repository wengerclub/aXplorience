LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := \
	TActivity

LOCAL_SRC_FILES := \
	op/Op.cpp \
	op/OpUnit.cpp \
	op/OpSquad.cpp \
	db/DBFile.cpp \
	db/DBHandler.cpp \
	device/graphics/Typeface.cpp \
	device/bluetooth/BluetoothAdapter.cpp \
	device/bluetooth/BluetoothDevice.cpp \
	device/bluetooth/BluetoothSocket.cpp \
	device/bluetooth/BluetoothServerSocket.cpp \
	native/NParamBox.cpp \
	native/NElement.cpp \
	native/NVisitor.cpp \
	native/NFrame.cpp \
	native/NClozer.cpp \
	native/NAPI.cpp \
	native/NWrapper.cpp \
	BOMessage.cpp \
	Network.cpp \
	OpUnitListener.cpp \
	OpUnitPeer.cpp \
	OpUnitServer.cpp \
	OpUnitCore.cpp \
	NActivity.cpp

LOCAL_LDLIBS := \
	-llog \
	-lm

include $(BUILD_SHARED_LIBRARY)

#LOCAL_CFLAGS := -Werror
#LOCAL_CFLAGS := -std=gnu++11
#LOCAL_CPP_FEATURES += exceptions
#LOCAL_CPPFLAGS += -fexceptions
#LOCAL_CPPFLAGS := -std=gnu++11
#LOCAL_CPPFLAGS += -std=c++11

#LOCAL_LDLIBS := \
#	-llog \
#	-ljnigraphics \
#	-lm \
#	-lGLESv2
