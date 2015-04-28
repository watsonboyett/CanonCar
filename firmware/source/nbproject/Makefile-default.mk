#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c motor.c rfm12.c digitalio.c util.c spi_util.c analogio.c controller.c io.c pins.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/motor.o ${OBJECTDIR}/rfm12.o ${OBJECTDIR}/digitalio.o ${OBJECTDIR}/util.o ${OBJECTDIR}/spi_util.o ${OBJECTDIR}/analogio.o ${OBJECTDIR}/controller.o ${OBJECTDIR}/io.o ${OBJECTDIR}/pins.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/motor.o.d ${OBJECTDIR}/rfm12.o.d ${OBJECTDIR}/digitalio.o.d ${OBJECTDIR}/util.o.d ${OBJECTDIR}/spi_util.o.d ${OBJECTDIR}/analogio.o.d ${OBJECTDIR}/controller.o.d ${OBJECTDIR}/io.o.d ${OBJECTDIR}/pins.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/motor.o ${OBJECTDIR}/rfm12.o ${OBJECTDIR}/digitalio.o ${OBJECTDIR}/util.o ${OBJECTDIR}/spi_util.o ${OBJECTDIR}/analogio.o ${OBJECTDIR}/controller.o ${OBJECTDIR}/io.o ${OBJECTDIR}/pins.o

# Source Files
SOURCEFILES=main.c motor.c rfm12.c digitalio.c util.c spi_util.c analogio.c controller.c io.c pins.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ128GP502
MP_LINKER_FILE_OPTION=,--script=p24HJ128GP502.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/motor.o: motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/motor.o.d 
	@${RM} ${OBJECTDIR}/motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  motor.c  -o ${OBJECTDIR}/motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rfm12.o: rfm12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/rfm12.o.d 
	@${RM} ${OBJECTDIR}/rfm12.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rfm12.c  -o ${OBJECTDIR}/rfm12.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rfm12.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/rfm12.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/digitalio.o: digitalio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/digitalio.o.d 
	@${RM} ${OBJECTDIR}/digitalio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  digitalio.c  -o ${OBJECTDIR}/digitalio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/digitalio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/digitalio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/util.o: util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/util.o.d 
	@${RM} ${OBJECTDIR}/util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  util.c  -o ${OBJECTDIR}/util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/util.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/spi_util.o: spi_util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/spi_util.o.d 
	@${RM} ${OBJECTDIR}/spi_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  spi_util.c  -o ${OBJECTDIR}/spi_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi_util.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/spi_util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/analogio.o: analogio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/analogio.o.d 
	@${RM} ${OBJECTDIR}/analogio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  analogio.c  -o ${OBJECTDIR}/analogio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/analogio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/analogio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controller.o: controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/controller.o.d 
	@${RM} ${OBJECTDIR}/controller.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controller.c  -o ${OBJECTDIR}/controller.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controller.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/controller.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/io.o: io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/io.o.d 
	@${RM} ${OBJECTDIR}/io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  io.c  -o ${OBJECTDIR}/io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/io.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/io.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pins.o: pins.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pins.o.d 
	@${RM} ${OBJECTDIR}/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pins.c  -o ${OBJECTDIR}/pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pins.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pins.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/motor.o: motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/motor.o.d 
	@${RM} ${OBJECTDIR}/motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  motor.c  -o ${OBJECTDIR}/motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motor.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/motor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/rfm12.o: rfm12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/rfm12.o.d 
	@${RM} ${OBJECTDIR}/rfm12.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rfm12.c  -o ${OBJECTDIR}/rfm12.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/rfm12.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/rfm12.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/digitalio.o: digitalio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/digitalio.o.d 
	@${RM} ${OBJECTDIR}/digitalio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  digitalio.c  -o ${OBJECTDIR}/digitalio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/digitalio.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/digitalio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/util.o: util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/util.o.d 
	@${RM} ${OBJECTDIR}/util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  util.c  -o ${OBJECTDIR}/util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/util.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/spi_util.o: spi_util.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/spi_util.o.d 
	@${RM} ${OBJECTDIR}/spi_util.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  spi_util.c  -o ${OBJECTDIR}/spi_util.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/spi_util.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/spi_util.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/analogio.o: analogio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/analogio.o.d 
	@${RM} ${OBJECTDIR}/analogio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  analogio.c  -o ${OBJECTDIR}/analogio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/analogio.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/analogio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/controller.o: controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/controller.o.d 
	@${RM} ${OBJECTDIR}/controller.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  controller.c  -o ${OBJECTDIR}/controller.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/controller.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/controller.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/io.o: io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/io.o.d 
	@${RM} ${OBJECTDIR}/io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  io.c  -o ${OBJECTDIR}/io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/io.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/io.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/pins.o: pins.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pins.o.d 
	@${RM} ${OBJECTDIR}/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pins.c  -o ${OBJECTDIR}/pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/pins.o.d"        -g -omf=elf -O0 -I"../C:/Program Files/Microchip/MPLAB C30/support/PIC24H/h" -I"../C:/Program Files/Microchip/MPLAB C30/support/peripheral_30F_24H_33F" -I".." -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/pins.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../C:/Program Files/Microchip/MPLAB C30/lib/PIC24H",--library-path="/Applications/microchip/xc16/v1.00/lib/PIC24H",--no-force-link,--smart-io,-Map="${DISTDIR}/StickControl.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="../C:/Program Files/Microchip/MPLAB C30/lib/PIC24H",--library-path="/Applications/microchip/xc16/v1.00/lib/PIC24H",--no-force-link,--smart-io,-Map="${DISTDIR}/StickControl.X.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/source.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
