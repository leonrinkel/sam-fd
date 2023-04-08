PROJ_NAME := sam-fd

CC := arm-none-eabi-gcc
LD := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
SIZE := arm-none-eabi-size

CFLAGS := \
	-mcpu=cortex-m0plus \
	-mthumb \
	-mlong-calls \
	-Os \
	-ffunction-sections \
	-g3 \
	-std=gnu99 \
	-Wall \
	-D__SAMC21E16A__ \
	-DDEBUG \

LDFLAGS := \
	-mcpu=cortex-m0plus \
	-mthumb \
	--specs=nano.specs \
	-Wl,--start-group \
	-Wl,--end-group \
	-Wl,--gc-sections \
	-T"../samc21/gcc/gcc/samc21e16a_flash.ld" \
	-L"../samc21/gcc/gcc" \
	-lm \

SRC_DIR := ..
INC_DIR := ..
OUT_DIR := out

OUT_ELF := $(OUT_DIR)/$(PROJ_NAME).elf
OUT_BIN := $(OUT_DIR)/$(PROJ_NAME).bin
OUT_HEX := $(OUT_DIR)/$(PROJ_NAME).hex

OBJS := \
	$(OUT_DIR)/hal/src/hal_io.o \
	$(OUT_DIR)/hal/src/hal_can_async.o \
	$(OUT_DIR)/hal/utils/src/utils_syscalls.o \
	$(OUT_DIR)/hal/src/hal_delay.o \
	$(OUT_DIR)/hal/utils/src/utils_list.o \
	$(OUT_DIR)/hal/utils/src/utils_assert.o \
	$(OUT_DIR)/hal/src/hal_usart_sync.o \
	$(OUT_DIR)/hal/src/hal_init.o \
	$(OUT_DIR)/hal/src/hal_gpio.o \
	$(OUT_DIR)/hal/utils/src/utils_event.o \
	$(OUT_DIR)/hal/src/hal_sleep.o \
	$(OUT_DIR)/hal/src/hal_atomic.o \
	$(OUT_DIR)/hpl/systick/hpl_systick.o \
	$(OUT_DIR)/hpl/can/hpl_can.o \
	$(OUT_DIR)/hpl/oscctrl/hpl_oscctrl.o \
	$(OUT_DIR)/hpl/core/hpl_init.o \
	$(OUT_DIR)/hpl/core/hpl_core_m0plus_base.o \
	$(OUT_DIR)/hpl/dmac/hpl_dmac.o \
	$(OUT_DIR)/hpl/pm/hpl_pm.o \
	$(OUT_DIR)/hpl/mclk/hpl_mclk.o \
	$(OUT_DIR)/hpl/gclk/hpl_gclk.o \
	$(OUT_DIR)/hpl/osc32kctrl/hpl_osc32kctrl.o \
	$(OUT_DIR)/hpl/sercom/hpl_sercom.o \
	$(OUT_DIR)/hpl/divas/hpl_divas.o \
	$(OUT_DIR)/samc21/gcc/system_samc21.o \
	$(OUT_DIR)/samc21/gcc/gcc/startup_samc21.o \
	$(OUT_DIR)/stdio_start.o \
	$(OUT_DIR)/stdio_redirect/stdio_io.o \
	$(OUT_DIR)/stdio_redirect/gcc/write.o \
	$(OUT_DIR)/stdio_redirect/gcc/read.o \
	$(OUT_DIR)/main.o \
	$(OUT_DIR)/atmel_start.o \
	$(OUT_DIR)/driver_init.o \
	$(OUT_DIR)/led.o \

OUT_DIRS := \
	$(OUT_DIR) \
	$(sort $(dir $(OBJS))) \

INCS := \
	-I"$(INC_DIR)/" \
	-I"$(INC_DIR)/CMSIS/Core/Include" \
	-I"$(INC_DIR)/config" \
	-I"$(INC_DIR)/hal/include" \
	-I"$(INC_DIR)/hal/utils/include" \
	-I"$(INC_DIR)/hpl/can" \
	-I"$(INC_DIR)/hpl/core" \
	-I"$(INC_DIR)/hpl/divas" \
	-I"$(INC_DIR)/hpl/dmac" \
	-I"$(INC_DIR)/hpl/gclk" \
	-I"$(INC_DIR)/hpl/mclk" \
	-I"$(INC_DIR)/hpl/osc32kctrl" \
	-I"$(INC_DIR)/hpl/oscctrl" \
	-I"$(INC_DIR)/hpl/pm" \
	-I"$(INC_DIR)/hpl/port" \
	-I"$(INC_DIR)/hpl/sercom" \
	-I"$(INC_DIR)/hpl/systick" \
	-I"$(INC_DIR)/hri" \
	-I"$(INC_DIR)/samc21/include" \
	-I"$(INC_DIR)/stdio_redirect" \

.PHONY: all clean

all: $(OUT_DIRS) $(OUT_ELF) $(OUT_BIN) $(OUT_HEX)

$(OUT_DIRS):
	@mkdir -p $@

$(OUT_ELF): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)
	$(SIZE) $@

$(OUT_BIN): $(OUT_ELF)
	$(OBJCOPY) -O binary $< $@

$(OUT_HEX): $(OUT_ELF)
	$(OBJCOPY) -O ihex $< $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCS)

clean:
	@rm -rf $(OUT_DIR)/*
