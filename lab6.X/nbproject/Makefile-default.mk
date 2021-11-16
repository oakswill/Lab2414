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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=uart.c inputcapture.c ../../Desktop/Lab414-main/lab5.X/tft_gfx.c ../../Desktop/Lab414-main/lab5.X/tft_master.c outputcapture.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/uart.o ${OBJECTDIR}/inputcapture.o ${OBJECTDIR}/_ext/1555163992/tft_gfx.o ${OBJECTDIR}/_ext/1555163992/tft_master.o ${OBJECTDIR}/outputcapture.o
POSSIBLE_DEPFILES=${OBJECTDIR}/uart.o.d ${OBJECTDIR}/inputcapture.o.d ${OBJECTDIR}/_ext/1555163992/tft_gfx.o.d ${OBJECTDIR}/_ext/1555163992/tft_master.o.d ${OBJECTDIR}/outputcapture.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/uart.o ${OBJECTDIR}/inputcapture.o ${OBJECTDIR}/_ext/1555163992/tft_gfx.o ${OBJECTDIR}/_ext/1555163992/tft_master.o ${OBJECTDIR}/outputcapture.o

# Source Files
SOURCEFILES=uart.c inputcapture.c ../../Desktop/Lab414-main/lab5.X/tft_gfx.c ../../Desktop/Lab414-main/lab5.X/tft_master.c outputcapture.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/e5120809cdc9586b74555b118b38f67ea4f837dd .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/inputcapture.o: inputcapture.c  .generated_files/flags/default/ecc7d171fdebf9afcf45137e17bf4458f6df3238 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/inputcapture.o.d 
	@${RM} ${OBJECTDIR}/inputcapture.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/inputcapture.o.d" -o ${OBJECTDIR}/inputcapture.o inputcapture.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/_ext/1555163992/tft_gfx.o: ../../Desktop/Lab414-main/lab5.X/tft_gfx.c  .generated_files/flags/default/18942b385b6c6f491386f1c2c854ff6095daffda .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}/_ext/1555163992" 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_gfx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_gfx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1555163992/tft_gfx.o.d" -o ${OBJECTDIR}/_ext/1555163992/tft_gfx.o ../../Desktop/Lab414-main/lab5.X/tft_gfx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/_ext/1555163992/tft_master.o: ../../Desktop/Lab414-main/lab5.X/tft_master.c  .generated_files/flags/default/929962e0c6cba6be6ec6312ac3f81b8457160f01 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}/_ext/1555163992" 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1555163992/tft_master.o.d" -o ${OBJECTDIR}/_ext/1555163992/tft_master.o ../../Desktop/Lab414-main/lab5.X/tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/outputcapture.o: outputcapture.c  .generated_files/flags/default/bd40d3d1743d898d58c093c54a18af98d98adcee .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/outputcapture.o.d 
	@${RM} ${OBJECTDIR}/outputcapture.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/outputcapture.o.d" -o ${OBJECTDIR}/outputcapture.o outputcapture.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
else
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/e4956e7b6ed5f229e259d59368b262cfe994d29e .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/inputcapture.o: inputcapture.c  .generated_files/flags/default/6cb8c9cf13ee20ce4ad92cab73b00b65f1a500be .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/inputcapture.o.d 
	@${RM} ${OBJECTDIR}/inputcapture.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/inputcapture.o.d" -o ${OBJECTDIR}/inputcapture.o inputcapture.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/_ext/1555163992/tft_gfx.o: ../../Desktop/Lab414-main/lab5.X/tft_gfx.c  .generated_files/flags/default/c9063e24eb8cd89194ee76fbb29c969c200245e5 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}/_ext/1555163992" 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_gfx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_gfx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1555163992/tft_gfx.o.d" -o ${OBJECTDIR}/_ext/1555163992/tft_gfx.o ../../Desktop/Lab414-main/lab5.X/tft_gfx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/_ext/1555163992/tft_master.o: ../../Desktop/Lab414-main/lab5.X/tft_master.c  .generated_files/flags/default/ab02bc8829cf876dca4dcdcef3887764c472b9f8 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}/_ext/1555163992" 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/1555163992/tft_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1555163992/tft_master.o.d" -o ${OBJECTDIR}/_ext/1555163992/tft_master.o ../../Desktop/Lab414-main/lab5.X/tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
${OBJECTDIR}/outputcapture.o: outputcapture.c  .generated_files/flags/default/ba1d0afbac4f0f180bf38ee6a4c656e63b7f85 .generated_files/flags/default/c9ab9a848ec860c15d50c34be9dd107a6274ab00
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/outputcapture.o.d 
	@${RM} ${OBJECTDIR}/outputcapture.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/outputcapture.o.d" -o ${OBJECTDIR}/outputcapture.o outputcapture.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -D_SUPPRESS PLIB WARNING   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc   -D_SUPPRESS PLIB WARNING $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc   -D_SUPPRESS PLIB WARNING $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/lab6.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
