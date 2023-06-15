#|***************************************************************************************
#|  Description: Makefile Template for Codesourcery Lite for ARM and the Olimexino STM32
#|    File Name: Olimexino_STM32_gcc.tmf
#|
#|---------------------------------------------------------------------------------------
#|                          C O P Y R I G H T
#|---------------------------------------------------------------------------------------
#|   Copyright 2013 (c) by HAN Automotive     http://www.han.nl     All rights reserved
#|
#|---------------------------------------------------------------------------------------
#|                            L I C E N S E
#|---------------------------------------------------------------------------------------
#| This file is part of the HANcoder Target Matlab/Simulink Blockset environment. For the
#| licensing terms, please contact HAN Automotive.
#|
#| This software has been carefully tested, but is not guaranteed for any particular
#| purpose. HAN Automotive does not offer any warranties and does not guarantee the 
#| accuracy, adequacy, or completeness of the software and is not responsible for any 
#| errors or omissions or the results obtained from use of the software.
#| 
#|***************************************************************************************


#|---------------------------------------------------------------------------------------
#| Macros read by make_rtw          
#|---------------------------------------------------------------------------------------
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
MAKECMD         = "%MATLAB%\bin\win64\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = any
COMPILER_TOOL_CHAIN = default


#|---------------------------------------------------------------------------------------
#| Tokens expanded by make_rtw
#|---------------------------------------------------------------------------------------
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of additional S-function modules.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
MODEL                = HANcoder_Olimexino_SV_MP
MODULES              = HANcoder_Olimexino_SV_MP_data.c
MAKEFILE             = HANcoder_Olimexino_SV_MP.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2022a
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2022a
MATLAB_BIN           = C:\Program Files\MATLAB\R2022a\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2022a\bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
NUMST                = 1
NCSTATES             = 0
BUILDARGS            = SHELL= HANcoder_PORTABLE=1 HANcoder_BOOTLOADER=1 GENERATE_ASAP2=1 OPTS="-DTID01EQ=0"
MULTITASKING         = 0
INTEGER_CODE         = 0
MAT_FILE             = 0
ONESTEPFCN           = 1
TERMFCN              = 0
B_ERTSFCN            = 0
MEXEXT               = mexw64
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000
MULTI_INSTANCE_CODE  = 0
MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
GEN_SAMPLE_MAIN         = 0
TARGET_LANG_EXT         = c
MEX_OPT_FILE            = 


#|---------------------------------------------------------------------------------------
#| Model and reference models
#|---------------------------------------------------------------------------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
MODELREF_TARGET_TYPE      = NONE


#|---------------------------------------------------------------------------------------
#| Environment Specifications
#|---------------------------------------------------------------------------------------
# In the case when directory name contains space
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

# Set the base path for the blockset.
ifeq ($(HANcoder_PORTABLE),1)
HANcoder_TARGET_BASE_PATH = $(RELATIVE_PATH_TO_ANCHOR)/blockset
else
HANcoder_TARGET_BASE_PATH = $(MATLAB_ROOT)
endif

# Adjust the model name for the specific controller
MODEL_NAME = $(MODEL)

# Set some commonly used paths
RTW_PATH     = $(HANcoder_TARGET_BASE_PATH)/rtw/STM32
TOOLBOX_PATH = $(HANcoder_TARGET_BASE_PATH)/toolbox/STM32
BIN_PATH     = $(RELATIVE_PATH_TO_ANCHOR)
CFG_PATH     = $(RTW_PATH)/cfg
CMD_PATH     = $(RTW_PATH)/cmd
INC_PATH     = $(RTW_PATH)/inc
SRC_PATH     = $(RTW_PATH)/src
LIB_PATH     = $(RTW_PATH)/lib

#|---------------------------------------------------------------------------------------|
#| Compiler binaries                                                                     |
#|---------------------------------------------------------------------------------------|
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
AR = arm-none-eabi-ar
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump
SZ = arm-none-eabi-size



#|---------------------------------------------------------------------------------------
#| Tool Specifications
#|---------------------------------------------------------------------------------------


#|---------------------------------------------------------------------------------------
#| Include Path
#|---------------------------------------------------------------------------------------
MATLAB_INCLUDES = \
	-I"$(MATLAB_ROOT)\simulink\include" \
	-I"$(MATLAB_ROOT)\extern\include" \
	-I"$(MATLAB_ROOT)\rtw\c\src"

COMPILER_INCLUDES =

# HANcoder Target includes
HANcoder_INCLUDES = \
	-I$(INC_PATH) \
	-I$(INC_PATH)/third_party/fatfs \
	-I$(INC_PATH)/third_party/canopennode \
	-I$(INC_PATH)/Olimexino_STM32 \
	-I$(SRC_PATH)/.. \
	-I$(SRC_PATH) \
	-I$(SRC_PATH)/third_party/canopennode \
	-I$(SRC_PATH)/third_party/fatfs \
	-I$(SRC_PATH)/third_party/fatfs/option \
	-I$(SRC_PATH)/Olimexino_STM32

# Additional includes
ADD_INCLUDES = \
	-I"C:\HANCOD~2.0-B\HANCOD~1.0\Target" \
	-I"C:\HANCOD~2.0-B\HANCOD~1.0\Target\HANcoder_Olimexino_SV_MP_ert_rtw" \
	-I"$(MATLAB_ROOT)\extern\include" \
	-I"$(MATLAB_ROOT)\simulink\include" \
	-I"$(MATLAB_ROOT)\rtw\c\src" \
	-I"$(MATLAB_ROOT)\rtw\c\src\ext_mode\common" \
	-I"$(MATLAB_ROOT)\rtw\c\ert" \


# see MATLAB_INCLUDES
SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif

CC_INCLUDES += -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) \
	$(COMPILER_INCLUDES) $(USER_INCLUDES) $(MODELREF_INC_PATH) \
	$(SHARED_INCLUDES) $(HANcoder_INCLUDES)

CC_INCLUDES += -I"$(MATLAB_ROOT)\rtw\c\ert"

AC_INCLUDES =

# Set the linker command file for either JTAG or Bootloader memory layout
ifeq ($(HANcoder_BOOTLOADER),1)
LINKER_LNK   = -T "$(CFG_PATH)\olimexino_stm32_boot.x"
else
LINKER_LNK   = -T "$(CFG_PATH)\olimexino_stm32_jtag.x"
endif


#|---------------------------------------------------------------------------------------
#| Tool flags
#|---------------------------------------------------------------------------------------
# MATLAB settings flags
CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DMT=$(MULTITASKING) -DMODEL_INITIALIZE=$(MODEL)_initialize \
		  -DMODEL_TERMINATE=$(MODEL)_terminate -DMODEL_STEP=$(MODEL)_step \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE)
# additional compiler flags
CC_FLAGS        += $(OPTS) $(CPP_REQ_DEFINES)
CC_FLAGS        += -DPACK_STRUCT_END=__attribute\(\(packed\)\) -DALIGN_STRUCT_END=__attribute\(\(aligned\(4\)\)\) 
CC_FLAGS        += -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DVECT_TAB_FLASH -DGCC_ARMCM3 -DFALSE=0 -DTRUE=1 
CC_FLAGS        += -O2 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -Wno-main -c -fmessage-length=0 -fno-zero-initialized-in-bss
CC_FLAGS        += -fsingle-precision-constant -mcpu=cortex-m3 -mthumb -g -Wno-maybe-uninitialized -Wno-unused-but-set-variable
CC_FLAGS        += -Wno-array-bounds
ifeq ($(HANcoder_BOOTLOADER),1)
CC_FLAGS        += -DHANcoder_BOOTLOADER=1
endif
# additional assembler flags
AS_FLAGS        +=
# additional librarian flags
AR_FLAGS        += -cr
# additional linker flags
LINKER_FLAGS     = $(LINKER_LNK) -nostartfiles -Xlinker --gc-sections -Wl,-Map,$(BIN_PATH)/$(MODEL_NAME).dump 
LINKER_FLAGS    += -mcpu=cortex-m3 -mthumb -g -lm
# additional object copy flags
OC_FLAGS         = -O srec
OC_FLAGS_BIN     = -O binary
# additional object dump flags
OD_FLAGS         = -D -t -z


#|---------------------------------------------------------------------------------------
#| Additional libraries
#|---------------------------------------------------------------------------------------
# HANcoder target specific libraries
LIBS += $(LIB_PATH)/HANcoder_Olimexino_STM32_RTL.a

# Other libraries (specified from Simulink)




LIBS += $(EXT_LIB) $(S_FUNCTIONS_LIB)


#|---------------------------------------------------------------------------------------
#| Source files
#|---------------------------------------------------------------------------------------
HANcoder_LIB_SRCS = \
  app.c anin.c can.c canio.c digin.c digout.c uart.c cstart.c os.c mac.c xcp_par.c \
  xcpBasic.c croutine.c list.c queue.c tasks.c timers.c port.c heap_4.c core_cm3.c \
  system_stm32f10x.c misc.c stm32f10x_adc.c stm32f10x_bkp.c stm32f10x_can.c stm32f10x_cec.c \
  stm32f10x_crc.c stm32f10x_dac.c stm32f10x_dbgmcu.c stm32f10x_dma.c stm32f10x_exti.c \
  stm32f10x_flash.c stm32f10x_fsmc.c stm32f10x_gpio.c stm32f10x_i2c.c stm32f10x_iwdg.c \
  stm32f10x_pwr.c stm32f10x_rcc.c stm32f10x_rtc.c stm32f10x_sdio.c stm32f10x_spi.c \
  stm32f10x_tim.c stm32f10x_usart.c stm32f10x_wwdg.c vectors.c quadencoder.c pwmout.c \
  errorcodes.c errorHandling.c eeprom.c reset.c eeprom_sim.c spi_master.c timein.c \
  ff.c unicode.c mmc.c filelogger.c ftoa.c usb_core.c usb_init.c usb_int.c usb_mem.c \
  usb_regs.c usb_sil.c usb_desc.c usb_endp.c usb_istr.c usb_prop.c usb_pwr.c usbcom.c \
  timeout.c tp.c diag.c CANopen.c CO_Emergency.c CO_HBconsumer.c CO_NMT_Heartbeat.c \
  CO_OD.c CO_PDO.c CO_SDO.c CO_SDOmaster.c CO_SYNC.c CO_driver.c CO_eeprom.c co_node.c \
  crc16-ccitt.c stackOverflowHook.c

  
ADD_SRCS = model.c

SRCS  = $(MODULES) $(ADD_SRCS) $(S_FUNCTIONS)
SRC_DEP =
PRODUCT = $(BIN_PATH)/$(MODEL_NAME).srec
BUILD_PRODUCT_TYPE = Motorola S-record file
SRCS += $(MODEL).$(TARGET_LANG_EXT) $(EXT_SRC)
ifeq ($(GEN_SAMPLE_MAIN),1)
  SRCS += ert_main.c
endif

USER_SRCS =

USER_OBJS = $(subst \,/, $(USER_SRCS:.c=.obj))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS_OBJS = $(addsuffix .obj, $(basename $(SRCS)))
OBJS      = $(SRCS_OBJS) $(USER_OBJS)
LINK_OBJS = $(SRCS_OBJS) $(LOCAL_USER_OBJS)

# only build the library if it is not already there
ifeq ($(wildcard $(LIB_PATH)/HANcoder_Olimexino_STM32_RTL.a), )
HANcoder_LIB_SRCS_OBJS = $(addsuffix .obj, $(basename $(HANcoder_LIB_SRCS)))
else
HANcoder_LIB_SRCS_OBJS =
endif


SHARED_OBJS := $(addsuffix .obj, $(basename $(wildcard $(SHARED_SRC))))
FMT_SHARED_OBJS = $(subst /,\,$(SHARED_OBJS))


#|---------------------------------------------------------------------------------------
#| Build rules
#|---------------------------------------------------------------------------------------
$(PRODUCT): $(BIN_PATH)/$(MODEL_NAME).elf
	@$(OD) $(OD_FLAGS) $< > $(BIN_PATH)/$(MODEL_NAME).map
	@echo ### Created Map file: $(MODEL_NAME).map
	@$(OC) $(OC_FLAGS_BIN) $< $(BIN_PATH)/$(MODEL_NAME).bin
	@echo ### Created Binary file: $(MODEL_NAME).bin
	@$(OC) $(OC_FLAGS) $< $@
	@echo ### Created $(BUILD_PRODUCT_TYPE): $(notdir $@)
	@echo ### Displaying program size info
	@$(SZ) --format=berkeley $<

$(LIB_PATH)/HANcoder_Olimexino_STM32_RTL.a: $(HANcoder_LIB_SRCS_OBJS)
	@$(AR) $(AR_FLAGS) $@ $^
	@echo ### Created $(notdir $@) run-time library
  
$(BIN_PATH)/$(MODEL_NAME).elf: clean $(OBJS) $(LIBS) $(SHARED_LIB) $(SRC_DEP) $(MODELREF_LINK_LIBS)
	@echo ### Linking $(notdir $@)
	@$(LD) -Wl,--start-group $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS) -Wl,--end-group \
        -o $@ $(LINKER_FLAGS)

%.obj : %.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(SRC_PATH)/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(LIB_PATH)/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(SRC_PATH)/../%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(SRC_PATH)/Olimexino_STM32/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(SRC_PATH)/third_party/canopennode/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(SRC_PATH)/third_party/fatfs/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

%.obj : $(SRC_PATH)/third_party/fatfs/option/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)
  
%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

ifeq ($(GEN_SAMPLE_MAIN),0)
%.obj : $(MATLAB_ROOT)/rtw/c/ert/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)
endif


%.obj : $(MATLAB_ROOT)\rtw\c\src\%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)
%.obj : $(MATLAB_ROOT)\simulink\src\%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)



#|---------------------------------------------------------------------------------------
#| Dependencies
#|---------------------------------------------------------------------------------------
$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_OBJS) : $(SHARED_BIN_DIR)/%.obj : $(SHARED_SRC_DIR)/%.c
	@echo ### Compiling $(notdir $<) -o $(notdir $@)
	@$(CC) -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo ### Creating $(notdir $@)
	@if exist $@ del $@
	$(LIBCMD) /out:$@ $(FMT_SHARED_OBJS)
	@echo ### $(notdir $@) Created


#|---------------------------------------------------------------------------------------
#| Project cleanup
#|---------------------------------------------------------------------------------------
clean :
	@echo ### Cleaning the objects and $(notdir $(PRODUCT))


#|----------------------------- end of Olimexino_STM32_gcc.tmf --------------------------
