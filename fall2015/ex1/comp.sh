arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp  -c -g -fno-common -fmessage-length=0 -Wall -Wextra -fno-exceptions -ffunction-sections -fdata-sections -fomit-frame-pointer -MMD -MP -DDEBUG -O0 -DTARGET_KPSDK_MCUS -DTARGET_FF_ARDUINO -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -DMBED_BUILD_TIMESTAMP=1448580807.66 -DCPU_MK64FN1M0VMD12 -DTARGET_FRDM -DTARGET_CORTEX_M -D__FPU_PRESENT=1 -DTARGET_KPSDK_CODE -DTARGET_M4 -D__MBED__=1 -DTARGET_K64F -DTARGET_Freescale -D__CORTEX_M4 -DFSL_RTOS_MBED -DTARGET_MCU_K64F -DARM_MATH_CM4  -std=gnu++98 -fno-rtti -o main.o main.cpp
arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp  -Wl,--gc-sections --specs=nano.specs -u _printf_float -u _scanf_float -Wl,--wrap,main -Wl,-Map=fall2015_frdm_gpio.map,--cref -T./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/K64FN1M0xxx12.ld -L./mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM  -o fall2015_frdm_gpio.elf main.o mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/startup_MK64F12.o -nostdlib 
#mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/board.o 
#mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/cmsis_nvic.o 
#mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/mbed_overrides.o 
#mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/retarget.o 
#mbed/TARGET_K64F/TOOLCHAIN_GCC_ARM/system_MK64F12.o -lmbed  -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys -lmbed  -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys
arm-none-eabi-objcopy -O binary fall2015_frdm_gpio.elf fall2015_frdm_gpio.bin
arm-none-eabi-size  fall2015_frdm_gpio.elf
