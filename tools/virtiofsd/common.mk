#
# Copyright 2016, QNX Software Systems Ltd. All Rights Reserved
#
# This source code has been published by QNX Software Systems Ltd. (QSSL).
# However, any use, reproduction, modification, distribution or transfer of
# this software, or any software which includes or is based upon any of this
# code, is only permitted under the terms of the QNX Community License version
# 1.0 (see licensing.qnx.com for details) or as otherwise expressly authorized
# by a written license agreement from QSSL. For more information, please email
# licensing@qnx.com.
#
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

define PINFO
PINFO DESCRIPTION="QNX virtio-fs vhost daemon"
endef

PUBLIC_INCVPATH = $(PRODUCT_ROOT)/../include $(PRODUCT_ROOT)/../include/standard-headers
EXTRA_INCVPATH = $(PRODUCT_ROOT)/..

CCFLAGS += -D_FILE_OFFSET_BITS=64 -D_IOFUNC_OFFSET_BITS=64 $(CCFLAGS_$(CPU))
#LDFLAGS += -Wl,-E

EXTRA_CCDEPS += $(PRODUCT_ROOT)/clean.timestamp

INSTALLDIR=sbin

USEFILE=$(PROJECT_ROOT)/usage.txt

#LIBS += hyp

include $(MKFILES_ROOT)/qtargets.mk
